#include"binary_trees.h"
/**
 * binary_tree_preorder - function that has responsible to make preorder
 * @tree: will receivng tree pointer
 * @func: Will receiving function pointer
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
