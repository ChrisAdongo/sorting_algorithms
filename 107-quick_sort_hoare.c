#include "sort.h"
#include <stdio.h>

/**
 * hoare_partition - Performs the Hoare partition scheme.
 * @array: The array to be sorted.
 * @low: The lower index of the partition to be sorted.
 * @high: The higher index of the partition to be sorted.
 * @size: The size of the array.
 * Return: The pivot index.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;
    int temp;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        /* Swap array[i] and array[j] */
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        print_array(array, size);
    }
}

/**
 * hoare_quick_sort - Recursively sorts an array using the Hoare partition scheme.
 * @array: The array to be sorted.
 * @low: The lower index of the partition to be sorted.
 * @high: The higher index of the partition to be sorted.
 * @size: The size of the array.
 */
void hoare_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot_idx;
    if (low < high)
    {
        pivot_idx = hoare_partition(array, low, high, size);

        hoare_quick_sort(array, low, pivot_idx, size);
        hoare_quick_sort(array, pivot_idx + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick sort (Hoare partition).
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    hoare_quick_sort(array, 0, (int)size - 1, size);
}

