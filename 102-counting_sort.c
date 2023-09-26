#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int max, min;
    size_t i;
    int *count_array, *output_array;

    if (array == NULL || size < 2)
        return;

    max = min = array[0];
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }

    count_array = malloc(sizeof(int) * (max - min + 1));
    if (count_array == NULL)
        return;

    output_array = malloc(sizeof(int) * size);
    if (output_array == NULL)
    {
        free(count_array);
        return;
    }

    for (i = 0; i < (size_t)(max - min + 1); i++)
        count_array[i] = 0;

    for (i = 0; i < size; i++)
        count_array[array[i] - min]++;

    print_array(count_array, max - min + 1);

    for (i = 1; i < (size_t)(max - min + 1); i++)
        count_array[i] += count_array[i - 1];

    for (i = size - 1; i != (size_t)-1; i--)
    {
        output_array[count_array[array[i] - min] - 1] = array[i];
        count_array[array[i] - min]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    free(count_array);
    free(output_array);
}

