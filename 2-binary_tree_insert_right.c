#include"binary_trees.h"
/**
 * binary_tree_insert_right - This function that will insert the
 * node at the right of binary tree
 * @parent: will receiving pointer to the right node
 * @value: will receiving value as data
 * Return: pointer to the reght node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node_right;

	new_node_right = binary_tree_node(parent, value);
	if (new_node_right == NULL)
	{
		return (NULL);
	}
	if (parent == NULL)
	{
		return (NULL);
	}
	if (parent->right != NULL)
	{
		new_node_right->right = parent->right;
		parent->right->parent = new_node_right;
	}
	parent->right = new_node_right;
	return (new_node_right);
}
