#include"binary_trees.h"

/**
 * binary_tree_inorder - Function that will display inorder binary tree
 * @tree: Will receiving the pointer to the node
 * @func: Will receiving function pointer that have responsible to display data
 * Return: return void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
