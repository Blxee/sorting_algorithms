#include "sort.h"

static int *g_array;
static size_t g_size;

/**
 * swap - swaps two indices in an array
 *
 * @array: target array
 * @i: first index
 * @j: second index
 */
void swap(int *array, size_t i, size_t j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;

	print_array(g_array, g_size);
}

/**
 * partition - splits array into lesser and greater elements than a pivot
 *
 * @array: the target array
 * @lo: lower index
 * @hi: higher index
 *
 * Return: the pivot index
 */
int partition(int *array, int lo, int hi)
{
	int i, j, pivot;

	pivot = hi;
	i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= array[pivot])
		{
			i++;
			swap(array, i, j);
		}
	}

	swap(array, i + 1, pivot);

	return (i + 1);
}

/**
 * recursive_quick_sort - helper function for quick_sort()
 *
 * @array: the target array
 * @lo: lower index
 * @hi: higher index
 */
void recursive_quick_sort(int *array, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(array, lo, hi);

		recursive_quick_sort(array, lo, p - 1);
		recursive_quick_sort(array, p + 1, hi);
	}
}

/**
 * quick_sort - sorts an array using the 'Quick Sort' algorithm
 *
 * @array: the target array (sorted in-place)
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	g_array = array;
	g_size = size;
	recursive_quick_sort(array, 0, size - 1);
}
