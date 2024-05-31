#include "binary_trees.h"

int binary_tree_balance(const binary_tree_t *tree);
/**
 * binary_tree_height - that will checking the height of a binary tree.
 * @tree: pointer to the root node of the tree height.
 *
 * Return: return the size of height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t y = 0, xx = 0;

		y = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		xx = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((y > xx) ? y : xx);
	}
	return (0);
}
/**
 * binary_tree_balance - function that will checking the balance factor
 * of a binary tree.
 * @tree: pointer to the root node the tree to the balance.
 *
 * Return: return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}
