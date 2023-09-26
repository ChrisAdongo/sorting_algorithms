#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail Shaker sort.
 * @list: Pointer to the doubly linked list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *left, *right, *current;
    int swapped = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        current = *list;

        while (current->next != NULL)
        {
            if (current->n > current->next->n)
            {
                if (current->prev != NULL)
                    current->prev->next = current->next;
                else
                    *list = current->next;
                current->next->prev = current->prev;
                current->prev = current->next;
                current->next = current->next->next;
                current->prev->next = current;
                if (current->next != NULL)
                    current->next->prev = current;
                swapped = 1;
                print_list(*list);
            }
            else
                current = current->next;
        }

        if (!swapped)
            break;

        swapped = 0;
        right = current;
        left = current->prev;

        while (left != NULL)
        {
            if (left->n > right->n)
            {
                if (right->next != NULL)
                    right->next->prev = left;
                left->prev->next = right;
                right->prev = left->prev;
                left->prev = right;
                left->next = right->next;
                right->next = left;
                if (left->next != NULL)
                    left->next->prev = left;
                swapped = 1;
                if (right->prev == NULL)
                    *list = right;
                print_list(*list);
            }
            right = left;
            left = left->prev;
        }
    }
}

