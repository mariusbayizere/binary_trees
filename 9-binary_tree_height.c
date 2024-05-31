#include"binary_trees.h"

/**
 * binary_tree_height - FUnction that will measure the hieght of binary tree
 * @tree: will recieve the tree of node
 * Return: hight of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t x = 0, y = 0;

		x = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		y = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((x > y) ? x : y);
	}
	return (0);
}
