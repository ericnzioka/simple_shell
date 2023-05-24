
Conversation opened. 1 read message.

Skip to content
Using Gmail with screen readers
Enable desktop notifications for Gmail.
   OK  No thanks
3 of 668
Shell
Inbox

Eric Muia <erick.muia.n@gmail.com>
Attachments
May 20, 2023, 4:33 PM (3 days ago)
to me


13
 Attachments
  •  Scanned by Gmail
#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	dup = malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);
	for (length++; length--;)
		dup[length] = *--str;
	return (dup);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */

void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 * Return: On success 1. On error, -1 and set errno appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[BUFFER_SIZE_WRITE];

	if (c == NEG_ONE || i >= BUFFER_SIZE_WRITE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != NEG_ONE)
		buf[i++] = c;
	return (1);
}
2_string_functions.c
Displaying 0_string_functions.c.
