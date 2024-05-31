#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle node of a given node in a binary tree.
 *
 * @node: Pointer to the node whose uncle is to be found.
 * Return: Pointer to the uncle node of the given node.
 *         or if the parent has no sibling, returns NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
