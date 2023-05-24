#include "main.h"
/**
 * words_count - counts the number of words in a string specified byrd and stores them in a count_array.
 * @str: the string being parsed.
 * @separators: delimiter(s) to separate the string.
 * @count_arr: Pointer to the array storing the lengths of the words.
 * Return: no. of words.
 */

int words_count(char *str, char *separators, unsigned int *count_arr)
{
	unsigned int c, d, length = 1;
	unsigned int count = 0;
	char *str_copy = str;
	bool start = false, delimiter;

	/* If the string is empty */
	if (!str)
		return (0);

	/* Shift string pointer to first non-delimiter character */
	while (!start)
		for (d = 0; separators[d]; d++)
		{
			if (*str_copy == separators[d])
				str_copy++;
			else
				start = true;
		}

	/* If the string has only one character */
	if (!*(str_copy + 1))
	{
		count_arr[0] = 1;
		return (1);
	}

	for (c = 1; str_copy[c]; c++)
	{
		/* Compare each delimiter with the current character */
		delimiter = is_delimiter(str_copy[c], separators);

		/* If current char is a delimiter and previous char is not */
		if (delimiter && !(is_delimiter(str_copy[c - 1], separators)))
		{
			count_arr[count] = length;
			count++;
		}

		/* If we're at the end of the string and its not a delimiter */
		if ((!str_copy[c + 1]) && !delimiter)
		{
			length++;
			count_arr[count] = length;
			count++;
			break;
		}

		if (!delimiter)
			length++;
		else
			length = 0;
	}

	return (count);
}
