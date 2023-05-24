
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
 * set_zeros - resets all the bytes of an integer array to 0
 * @arr: Array to be initialized.
 * @size: Size of the array.
 * Return: Nothing
 */

void set_zeros(unsigned int *arr, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		arr[i] = 0;
}

/**
 * set_nulls - resets a char array to nulls
 * @arr: Array to be initialized.
 * @size: Size of the array.
 * Return: Nothing
 */

void set_nulls(char *arr, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		arr[i] = '\0';
}
memset.c
Displaying 0_string_functions.c.
