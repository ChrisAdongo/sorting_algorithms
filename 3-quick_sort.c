#include "sort.h"

void divide_array(int begin, int pivot, int *arr, size_t size);
int partition_array(int begin, int pivot, int *arr, size_t size);
void swap_integers(int *a, int *b);

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int begin = 0, pivot;

	if (array && size > 1)
	{
		pivot = (size - 1);
		divide_array(begin, pivot, array, size);
	}
}

/**
 * divide_array - recursively partition
 * @begin: beginning of divided array
 * @pivot: end of divided array
 * @arr: the beginning of the array
 * @size: size of array
 **/
void divide_array(int begin, int pivot, int *arr, size_t size)
{
	int first, second, new_pivot;

	if (begin < pivot)
	{
		second = partition_array(begin, pivot, arr, size);
		first = begin;
		new_pivot = second - 1;
		if (first != new_pivot && second != pivot)
			new_pivot--;
		divide_array(first, new_pivot, arr, size);
		divide_array(second, pivot, arr, size);
	}
}

/**
 * partition_array - divides an array
 * @begin: beginning of array separated
 * @pivot: end of array separated
 * @arr: the beginning of array
 * @size: size of array
 * Return: the new beginning
 **/
int partition_array(int begin, int pivot, int *arr, size_t size)
{
	int temp;

	temp = begin;
	while (temp != pivot)
	{
		if (arr[temp] < arr[pivot])
		{
			if (temp != begin)
			{
				swap_integers(arr + temp, arr + begin);
				print_array(arr, size);
			}
			temp++;
			begin++;
		}
		else
			temp++;
	}
	if (begin != pivot)
	{
		if (arr[begin] > arr[pivot])
		{
			swap_integers(arr + pivot, arr + begin);
			print_array(arr, size);
		}
		begin++;
	}
	return (begin);
}

/**
 * swap_integers - swaps the values of two integers
 * @a: take an int
 * @b: take an int
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
