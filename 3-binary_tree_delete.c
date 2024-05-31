#include"binary_trees.h"

/**
 * binary_tree_delete - function that will delete entire binary tree
 * @tree: will receiving the tree as location delete
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		exit(1);
	}
	else
	{
		binary_tree_delete(tree->right);
		binary_tree_delete(tree->left);
		free(tree);
	}
}


