#include "sort.h"

/**
 * selection_sort - sorts an array using the 'Selection Sort' algorithm
 *
 * @array: the target array (sorted in-place)
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned long i, j;
	int tmp;

	if (!array || size < 2)
		return;

	for (j = size - 1; j > 0; j--)
	{
		for (i = 0; i < j; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
