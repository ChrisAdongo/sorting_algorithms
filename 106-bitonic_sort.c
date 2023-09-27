#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * bitonic_compare - Compares two elements and swaps if needed.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_compare(int *array, size_t size, int dir)
{
    size_t step = size / 2;
    size_t i, tmp;

    for (i = 0; i < step; i++)
    {
        if ((array[i] > array[i + step]) == dir)
        {
            tmp = array[i];
            array[i] = array[i + step];
            array[i + step] = tmp;
        }
    }
}

/**
 * bitonic_merge - Recursively merges two bitonic sequences.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t half = size / 2;

        printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
        print_array(array, size);

        bitonic_compare(array, size, dir);
        bitonic_merge(array, half, dir);
        bitonic_merge(array + half, half, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive function to perform Bitonic Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t half = size / 2;

        printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
        print_array(array, size);

        bitonic_sort_recursive(array, half, 1);
        bitonic_sort_recursive(array + half, half, 0);

        bitonic_merge(array, size, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_sort_recursive(array, size, 1);
}

