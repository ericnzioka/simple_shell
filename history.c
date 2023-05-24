#include "main.h"

/**
 * read_hist - gets the history file
 * @info: parameter struct
 * Return: allocated string containg history file
 */

char *read_hist(info_s *info)
{
	char *buffer, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE_NAME) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, dir);
	_strcat(buffer, "/");
	_strcat(buffer, HIST_FILE_NAME);
	return (buffer);
}

/**
 * create_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 * Return: 1 on success, else -1
 */
int create_history(info_s *info)
{
	ssize_t fd;
	char *filename = read_hist(info);
	list_s *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		write_chars(node->str, fd);
		write_char('\n', fd);
	}
	write_char(NEG_ONE, fd);
	close(fd);
	return (1);
}

/**
 * read_history - reads history from file
 * @info: the parameter struct
 * Return: hist_lines on success, 0 otherwise
 */
int read_history(info_s *info)
{
	int j, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buffer = NULL, *filename = read_hist(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fsize + 1));
	if (!buffer)
		return (0);
	rdlen = read(fd, buffer, fsize);
	buffer[fsize] = 0;
	if (rdlen <= 0)
		return (free(buffer), 0);
	close(fd);
	for (j = 0; j < fsize; j++)
		if (buffer[j] == '\n')
		{
			buffer[j] = 0;
			update_history(info, buffer + last, linecount++);
			last = j + 1;
		}
	if (last != j)
		update_history(info, buffer + last, linecount++);
	free(buffer);
	info->hist_lines = linecount;
	while (info->hist_lines-- >= HIST_SIZE_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->hist_lines);
}

/**
 * update_history - adds entry to a history linked list
 * @info: contains simulated arguments for a function pointer,
 * @buffer: buffer
 * @linecount: the history linecount, hist_lines
 * Return: Always 0
 */
int update_history(info_s *info, char *buffer, int linecount)
{
	list_s *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buffer, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @info: contains simulated arguments for a function pointer,
 * Return: the new hist_lines
 */
int renumber_history(info_s *info)
{
	list_s *node = info->history;
	int j = 0;

	while (node)
	{
		node->num = j++;
		node = node->next;
	}
	return (info->hist_lines = j);
}
