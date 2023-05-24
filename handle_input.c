#include "main.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 * Return: bytes read
 */
ssize_t input_buf(info_s *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, handle_sigint);
#if USE_GETLINE
		r =_getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->lc_flag = 1;
			handle_comments(*buf);
			update_history(info, *buf, info->hist_lines++);
			{
				*len = r;
				info->sep_buff = buf;
			}
		}
	}
	return (r);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 * Return: bytes read
 */
ssize_t get_input(info_s *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(NEG_ONE);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(info, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->sep_buff_kind = REG_FLAG;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (r);

	/**
	 * read_buf - reads a buffer
	 * @info: parameter struct
	 * @buf: buffer
	 * @i: size
	 * Return: r
	 */
	ssize_t read_buf(info_s * info, char *buf, size_t *i)
	{
		ssize_t r = 0;

		if (*i)
			return (0);
		r = read(info->fd_read, buf, BUFFER_SIZE_READ);
		if (r >= 0)
			*i = r;
		return (r);
	}

	/**
	 * _getline - gets the next line of input from STDIN
	 * @info: parameter struct
	 * @ptr: address of pointer to buffer, preallocated or NULL
	 * @length: size of preallocated ptr buffer if not NULL
	 *
	 * Return: s
	 */
	int _getline(info_s * info, char **ptr, size_t *length)
	{
		static char buf[BUFFER_SIZE_READ];
		static size_t i, len;
		size_t k;
		ssize_t r = 0, s = 0;
		char *p = NULL, *new_p = NULL, *c;

		p = *ptr;
		if (p && length)
			s = *length;
		if (i == len)
			i = len = 0;

		r = read_buf(info, buf, &len);
		if (r == -1 || (r == 0 && len == 0))
			return (-1);
		c = _strchr(buf + i, '\n');
		k = c ? 1 + (unsigned int)(c - buf) : len;
		new_p = _realloc(p, s, s ? s + k : k + 1);
		if (!new_p)
			return (p ? free(p), -1 : -1);
		if (s)
			_strncat(new_p, buf + i, k - i);
		else
			_strncpy(new_p, buf + i, k - i + 1);

		s += k - i;
		i = k;
		p = new_p;

		if (length)
			*length = s;
		*ptr = p;
		return (s);
	}

	/**
	 * handle_sigint - blocks ctrl-C
	 * @sig_num: the signal number
	 * Return: void
	 */
	void handle_sigint(__attribute__((unused)) int sig_num)
	{
		_puts("\n");
		_puts("$ ");
		_putchar(NEG_ONE);
	}
