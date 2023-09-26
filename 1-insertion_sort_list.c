#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm.
 *
 * @list: Pointer to the pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;
	prev = NULL;

	while (current != NULL)
	{
		next = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            prev = current->prev;
            prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev;
            current->next = prev;
            current->prev = prev->prev;
            prev->prev = current;

            if (current->prev == NULL)
                *list = current;

            if (prev->next != NULL)
                prev->next->prev = prev;
            prev->next = prev->prev->next;
            prev->prev->next = prev;
            prev->prev = current;

            print_list(*list);
        }

        current = next;
    }
}
