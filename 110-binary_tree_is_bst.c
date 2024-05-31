#include "binary_trees.h"
#include "limits.h"

/**
 * searching_element - This function will Checks if a binary tree
 * is a Binary Search Tree (BST) within a given range..
 * @tree: Pointer to the root node of the binary tree.
 * @temp: The minimum allowable value for
 * any node in the subtree rooted at `tree`.
 * @elhag: The maximum allowable value for any
 * node in the subtree rooted at `tree`.
 *
 * Return: returns 1 if the binary tree rooted at `tree`
 */
int searching_element(const binary_tree_t *tree, int temp, int elhag)
{
	if (tree != NULL)
	{
		if (tree->n < temp || tree->n > elhag)
			return (0);
		return (searching_element(tree->left, temp, tree->n - 1) &&
			searching_element(tree->right, tree->n + 1, elhag));
	}
	return (1);
}

/**
 * binary_tree_is_bst - This function will Checks if a binary
 * tree is a Binary Search Tree (BST) within a given range.
 * @tree: Pointer to the root node of the binary tree.
 * Return: returns 1 if the binary tree rooted at `tree`
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (searching_element(tree, INT_MIN, INT_MAX));
}
