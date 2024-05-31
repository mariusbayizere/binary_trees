#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling node of
 * given node in a binary tree.
 *
 * @node: Pointer to the node whose sibling
 * Return: Pointer to the sibling node of the given node.
 *         If the given node is NULL,
 *         returns NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
