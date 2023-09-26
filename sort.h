#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>

/* Structure for doubly linked list */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms*/
void bubble_sort(int *array, size_t size);
int sort(void);

#endif /* SORT_H */

