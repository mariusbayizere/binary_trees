#include "binary_trees.h"

/**
 * array_to_heap - function will builds a Max Binary Heap tree from an array
 * @array: will receive pointer to the first element of the array
 * @size: will receiving the size.
 *
 * Return: will return the pointer to temp
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int x;
	heap_t *temp = NULL;

	for (x = 0; x < size; x++)
		heap_insert(&temp, array[x]);

	return (temp);
}
