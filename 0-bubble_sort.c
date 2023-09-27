#include "sort.h"
#include <stdio.h>
#include <inttypes.h>

/**
 * bubble_sort - Sorts an array of ints in ascending ordr using Bubble sort.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	int swapped;

	size_t i, j, k;

	for (i = 0; i < size - 1; i++)

	{
		swapped = 0;  /* Flag to check if any swaps were made in this pass */

		for (j = 0; j < size - 1 - i; j++)
		{
			/* If the current element is greater than the next element, swap them */
			if (array[j] > array[j + 1])
			{
				/* Swap */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;  /* Set the swapped flag to true */
			}
		}
		/* Print the array after this pass */
		printf("After pass %lu: ",(unsigned long)( i + 1));
		for (k = 0; k < size; k++)
		{
			printf("%d ", array[k]);
		}
		printf("\n");
		/* If no swaps were made in this pass, the array is already sorted */
		if (swapped == 0)
		{
			break;
		}
	}
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 */
int sort(void)
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	size_t i;

	printf("Original array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");

	bubble_sort(arr, size);

	printf("Sorted array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
		if (i < size - 1)
		printf(", ");
	}
	printf("\n");

	return (0);
}
