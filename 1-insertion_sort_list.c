#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked
 * list of integers in ascending order using Insertion Sort.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *current;
	listint_t *back;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current->next;
		back = current->prev;

		while (back && back->n > current->n)
		{
			if (back->prev)
				back->prev->next = current;
			else
				*list = current;

			if (current->next)
				current->next->prev = back;

			back->next = current->next;
			current->prev = back->prev;
			current->next = back;
			back->prev = current;

			print_list(*list);

			back = current->prev;
		}

		current = temp;
	}
}
