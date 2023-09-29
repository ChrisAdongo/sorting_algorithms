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
listint_t *create_listint(const int *array, size_t size);

/* Sorting algorithms*/
void bubble_sort(int *array, size_t size);
int sort(void);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);
void merge_sort_helper(int *array, int *temp, size_t left, size_t right);
void merge_sort(int *array, size_t size);
void heapify(int *array, size_t size, int i);
void heap_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void counting_sort(int *array, size_t size);
void counting_sorter(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void bitonic_compare(int *array, size_t size, int dir);
void bitonic_merge(int *array, size_t size, int dir);
void bitonic_sort_recursive(int *array, size_t size, int dir);
void bitonic_sort(int *array, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void hoare_quick_sort(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);
void divide_array(int begin, int pivot, int *arr, size_t size);
int partition_array(int begin, int pivot, int *arr, size_t size);
void swap_integers(int *a, int *b);

#endif /* SORT_H */

