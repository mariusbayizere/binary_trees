#include "binary_trees.h"


int isFullTree(const binary_tree_t *tree);
/**
 * binary_tree_is_full - Checking if a binary tree is full.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: tree is NULL or is not full true or flase.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (isFullTree(tree));
}
/**
 * isFullTree - checking if  binary tree is full recursively.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: return tree is not full, 0.
 */
int isFullTree(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    isFullTree(tree->left) == 0 ||
		    isFullTree(tree->right) == 0)
			return (0);
	}
	return (1);
}
