#include"binary_trees.h"

/**
 * binary_tree_is_leaf - function that will check if leaf or not
 * @node: will receiving the node
 * Return: interger
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left == NULL || node->right)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
