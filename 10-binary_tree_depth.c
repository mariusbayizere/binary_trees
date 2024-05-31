#include"binary_trees.h"
/**
 * binary_tree_depth - function that calculate height of depth in binary tree
 * @tree: will receiving the pointer to the root
 * Return: height of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
