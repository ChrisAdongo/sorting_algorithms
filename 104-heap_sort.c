#include "sort.h"
#include <stdio.h>

/**
 * heapify - Builds a max heap from an array.
 * @array: The array to be turned into a max heap.
 * @size: The size of the array.
 * @i: The index to start heapifying from.
 */
void heapify(int *array, size_t size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        print_array(array, size);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    int i;
    
    if (array == NULL || size < 2)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    for (i = size - 1; i >= 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        if (i != 0)
            print_array(array, size);
        heapify(array, i, 0);
    }
}

