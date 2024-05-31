#include "binary_trees.h"

/**
 * binary_tree_rotate_right - This function will
 * checking right-rotates a binary tree.
 * @tree: will receiving pointer to root of the tree to rotate.
 * Return: return pointer to root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *header;
	binary_tree_t *footer;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	header = tree->left;
	footer = header->right;
	header->right = tree;
	tree->left = footer;
	if (footer != NULL)
		footer->parent = tree;
	footer = tree->parent;
	tree->parent = header;
	header->parent = footer;
	if (footer != NULL)
	{
		if (footer->left == tree)
			footer->left = header;
		else
			footer->right = header;
	}

	return (header);
}
