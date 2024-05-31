#include "binary_trees.h"

/**
 * array_to_avl - function that have responsablity to build the AVL.
 * @array: will receive the pointer to the array.
 * @size: will receiving the size of array.
 * Return: return the success node AVL tree.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *pointer = NULL;
	size_t x;
	size_t y;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (avl_insert(&pointer, array[x]) == NULL)
				return (NULL);
		}
	}

	return (pointer);
}
