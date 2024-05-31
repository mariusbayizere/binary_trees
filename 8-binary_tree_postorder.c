#include"binary_trees.h"

/**
 * binary_tree_postorder - Function that have will Display postorder
 * @tree: will receive root to node
 * @func: will recive function pointer which will print data where are reach
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
