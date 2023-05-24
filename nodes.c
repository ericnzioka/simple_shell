
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
 * _listlen - gets the length of linked list
 * @h: Pointer to first node.
 * Return: Size of list.
 */
size_t _listlen(const list_s *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_vector - returns an array of strings of the list->str
 * @head: pointer to first node
 * Return: Array of strings.
 */

char **list_to_vector(list_s *head)
{
	list_s *nod = head;
	size_t i = _listlen(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));

	if (!strs)
		return (NULL);
	for (i = 0; nod; nod = nod->next, i++)
	{
		str = malloc(_strlen(nod->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, nod->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - prints all elements of a list_s linked list
 * @h: pointer to first node
 * Return: Size of list
 */

size_t print_list(const list_s *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(change_base(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_str_start - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to check
 * @c: the next character after prefix to check
 * Return: match node or null
 */

list_s *node_str_start(list_s *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Return: -1 or index of node
 */

ssize_t get_node_index(list_s *head, list_s *node)
{
	size_t j = 0;

	while (head)
	{
		if (head == node)
			return (j);
		head = head->next;
		j++;
	}
	return (-1);
}
nodes.c
Displaying 0_string_functions.c.
