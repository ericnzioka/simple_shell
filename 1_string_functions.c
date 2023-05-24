
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
**_strncpy - copies a string
*@dest: the destination string to be copied to
*@src: the source string
*@n: the amount of characters to be copied
*Return: the concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
**_strncat - concatenates two strings
*@dest: the first string
*@src: the second string
*@n: the amount of bytes to be maximally used
*Return: the concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
**_strchr - locates a character in a string
*@s: the string to be parsed
*@c: the character to look for
*Return: (s) a pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
	do
	{
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
1_string_functions.c
Displaying 0_string_functions.c.
