#include "binary_trees.h"

/**
 * binary_tree_is_root - funtion that will checking if the node is root
 * @node: will receive pointer to the node
 * Return: root
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node->right == NULL || node->left == NULL)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
