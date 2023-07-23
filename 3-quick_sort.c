#include "sort.h"

/**
 * recursive_quick_sort - helper function for quick_sort()
 *
 * @array: the target array (sorted in-place)
 * @array_size: the size of the array
 * @chunk: the current chunk
 * @chunk_size: the current chunk size
 */
void recursive_quick_sort(
	int *array, size_t array_size,
	int *chunk, size_t chunk_size)
{
	unsigned long left, pivot;
	int tmp;

	if (chunk_size < 2)
		return;

	pivot = chunk_size - 1;
	left = 0;

	while (left < pivot)
	{
		while (left < pivot && chunk[left] < chunk[pivot])
			left++;

		if (pivot == left)
			break;

		tmp = chunk[left];
		chunk[left] = chunk[pivot];
		chunk[pivot] = tmp;
		print_array(array, array_size);
	}

	if (pivot != left)
	{
		tmp = chunk[pivot];
		chunk[pivot] = chunk[left];
		chunk[left] = tmp;
		print_array(array, array_size);
	}

	recursive_quick_sort(array, array_size, chunk, left);
	recursive_quick_sort(
		array, array_size,
		chunk + (left + 1), chunk_size - left - 1);
}

/**
 * quick_sort - sorts an array using the 'Quick Sort' algorithm
 *
 * @array: the target array (sorted in-place)
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	recursive_quick_sort(array, size, array, size);
}
