#include "sort.h"

/**
 * bubble_sort - sorts an array using the 'Bubble Sort' algorithm
 *
 * @array: the target array (sorted in-place)
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long i, j;
	int tmp;

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
