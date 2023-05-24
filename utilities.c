
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
 * from_terminal - returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if from_terminal mode else 0
 */

int from_terminal(info_s *info)
{
	return (isatty(STDIN_FILENO) && info->fd_read <= 2);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic else 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to integer
 * @s: the string to be converted
 * Return: Converted integer or 0 if no numbers in string
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}

/**
 * is_delimiter - This function compares a character to one or more of delimiters
 * 					to see if the character matches any of the delimiters.
 * @c: Character to be checked.
 * @delim: String of charaters to be compared.
 * Return: True if it is a delimiter, else false.
 */

bool is_delimiter(char c, char *delim)
{
	int s;

	for (s = 0; delim[s]; s++)
		if (c == delim[s])
			return (true);
	return (false);
}
utilities.c
Displaying 0_string_functions.c.
