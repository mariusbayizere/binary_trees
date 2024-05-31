#include"binary_trees.h"

/**
 * binary_tree_size - function that will calculate the size binary tree
 * @tree: Will receive the pointer to the binary tree
 * Return: the size of binary include left and right
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree != NULL)
	{
		counter = counter + 1;
		counter = counter + binary_tree_size(tree->left);
		counter = counter + binary_tree_size(tree->right);
	}
	return (counter);
}
