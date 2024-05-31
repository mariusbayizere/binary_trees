#include "binary_trees.h"

/**
 * bst_search - Searches for a specific value
 * in a Binary Search Tree (BST).
 * @tree: Pointer to the root node of the BST to search.
 * @value: The value to search for in the BST.
 * Return: If the tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
