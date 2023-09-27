#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - Returns the maximum element from the array.
 * @array: The array to find the maximum from.
 * @size: The size of the array.
 * Return: The maximum element.
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

/**
 * counting_sorter - Sorts the array based on a significant digit using Counting Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current significant digit.
 */
void counting_sorter(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};
    int i;

    if (!output)
        return;

    for (i = 0; i < (int)size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < (int)size; i++)
    {
        array[i] = output[i];
    }

    print_array(array, size);

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using LSD Radix Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int max;
    int exp;

	if (!array || size < 2)
        return;

   max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sorter(array, size, exp);
    }
}

