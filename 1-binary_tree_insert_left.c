#include"binary_trees.h"

/**
 * binary_tree_insert_left - This function will insert node on
 * the left of binary tree
 * @parent: will receiving the pointer to node
 * @value: will receiving value as data
 * Return: ponter to new inserted
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
