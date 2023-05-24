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
