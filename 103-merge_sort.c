#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays into one sorted array.
 * @array: The original array.
 * @temp: A temporary array for merging.
 * @left: The left subarray to merge.
 * @mid: The middle index.
 * @right: The right subarray to merge.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left;
    size_t j = mid;
    size_t k = left;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, mid - left);
    printf("[right]: ");
    print_array(array + mid, right - mid);

    while (i < mid && j < right)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i < mid)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j < right)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (i = left; i < right; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_sort_helper - Recursive helper function for merge sort.
 * @array: The original array.
 * @temp: A temporary array for merging.
 * @left: The left index of the subarray.
 * @right: The right index of the subarray.
 */
void merge_sort_helper(int *array, int *temp, size_t left, size_t right)
{
    size_t mid;

	if (right - left <= 1)
        return;

   mid = left + (right - left) / 2;

    merge_sort_helper(array, temp, left, mid);
    merge_sort_helper(array, temp, mid, right);
    merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(sizeof(int) * size);

    if (temp == NULL)
        return;

    merge_sort_helper(array, temp, 0, size);

    free(temp);
}

