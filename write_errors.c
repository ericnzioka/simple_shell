#include "main.h"
/**
 * puts_err - prints input string
 * @str: the string to be printed
 * Return: void
 */

void puts_err(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		putchar_err(str[j]);
		j++;
	}
	return;
}
/**
 * putchar_err - writes the character c to stderr
 * @b: The character to print
 * Return: On success 1.
 * On failure, -1 is returned
 */
int putchar_err(char b)
{
	static int j;
	static char buf[BUFFER_SIZE_WRITE];

	if (b == NEG_ONE || j >= BUFFER_SIZE_WRITE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (b != NEG_ONE)
		buf[j++] = b;
	return (1);
}
/**
 * write_char - writes the character b to given fd
 * @b: The character to be printed
 * @fd: The filedescriptor
 * Return: On success 1.
 */
int write_char(char b, int fd)
{
	static int j;
	static char buf[BUFFER_SIZE_WRITE];

	if (b == NEG_ONE || j >= BUFFER_SIZE_WRITE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (b != NEG_ONE)
		buf[j++] = b;
	return (1);
}
/**
 * write_chars - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor
 * Return: the number of chars put
 */
int write_chars(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += write_char(*str++, fd);
	}
	return (j);
}
