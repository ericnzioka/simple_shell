#include "main.h"
/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: s- a pointer to the memory area of s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * free_vector - frees memory allocated to a 2D character array
 * @vec: Vector to be freed.
 * Return: Nothing.
 */

void free_vector(char **vec)
{
	char **buff = vec;

	if (!vec)
		return;
	while (*vec)
		free(*vec++);

	free(buff);
}

/**
 * _realloc - reallocates a block of memory
 * @buff: pointer to previous memory allocated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer of old block.
 */
void *_realloc(void *buff, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!buff)
		return (malloc(new_size));
	if (!new_size)
		return (free(buff), NULL);
	if (new_size == old_size)
		return (buff);
	p = malloc(new_size);
	if (!p)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)buff)[old_size];
	free(buff);
	return (p);
}

#include "main.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @buff: address of the pointer to free
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **buff)
{
	if (buff && *buff)
	{
		free(*buff);
		*buff = NULL;
		return (1);
	}
	return (0);
}
