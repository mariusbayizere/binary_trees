#include "binary_trees.h"
#include "limits.h"

int binary_tree_is_avl(const binary_tree_t *tree);
size_t Line_Hight_binary(const binary_tree_t *tree);
int averaage_hight(const binary_tree_t *tree, int xx, int yy);

/**
 * averaage_hight - function that will checking
 * binary tree is a valid AVL tree.
 * @tree: will receiving pointer to root node of the tree.
 * @xx: will receiving value of node to be visited.
 * @yy: will receiving largest node to be visit.
 * Return: return 0
 */
int averaage_hight(const binary_tree_t *tree, int xx, int yy)
{
	size_t compore;
	size_t zich;
	size_t temp;

	if (tree != NULL)
	{
		if (tree->n < xx || tree->n > yy)
			return (0);
		zich = Line_Hight_binary(tree->left);
		temp = Line_Hight_binary(tree->right);
		compore = zich > temp ? zich - temp : temp - zich;
		if (compore > 1)
			return (0);
		return (averaage_hight(tree->left, xx, tree->n - 1) &&
			averaage_hight(tree->right, tree->n + 1, yy));
	}
	return (1);
}

/**
 * binary_tree_is_avl - function that will
 * checking if the binary tree is a right way in AVL tree.
 * @tree: will receiving the pointer to node of the tree to check.
 * Return: returning 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (averaage_hight(tree, INT_MIN, INT_MAX));
}

/**
 * Line_Hight_binary - this function are used to check
 * the Line_Hight_binary of a binary tree.
 * @tree: A pointer to the root node of the tree to
 * measure the Line_Hight_binary.
 * Return: return 0.
 */
size_t Line_Hight_binary(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t length = 0, row = 0;

		length = tree->left ? 1 + Line_Hight_binary(tree->left) : 1;
		row = tree->right ? 1 + Line_Hight_binary(tree->right) : 1;
		return ((length > row) ? length : row);
	}
	return (0);
}
