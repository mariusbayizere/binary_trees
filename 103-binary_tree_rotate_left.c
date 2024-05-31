#include "binary_trees.h"

/**
 * binary_tree_rotate_left - This function will check Left-rotates
 * a binary tree.
 * @tree: will receive pointer to the root tree to rotate.
 * Return: A pointer to the root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *footer;
	binary_tree_t *header;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	footer = tree->right;
	header = footer->left;
	footer->left = tree;
	tree->right = header;
	if (header != NULL)
		header->parent = tree;
	header = tree->parent;
	tree->parent = footer;
	footer->parent = header;
	if (header != NULL)
	{
		if (header->left == tree)
			header->left = footer;
		else
			header->right = footer;
	}

	return (footer);
}
