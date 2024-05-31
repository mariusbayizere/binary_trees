#include "binary_trees.h"

/**
 * array_to_bst - converts a sorted array of integers
 * into a Binary Search Tree (BST).
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 * Return: pointer to root
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t x, y;

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
			if (bst_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
