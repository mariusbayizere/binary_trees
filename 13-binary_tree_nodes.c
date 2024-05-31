#include"binary_trees.h"
/**
 * binary_tree_nodes - function that will calculate the leaves of binary tree
 * @tree: will receive pointer to the node
 * Return:return the size of the leaves
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree != NULL)
	{i	counter += (tree->left || tree->right) ? 1 : 0;
		counter = counter + binary_tree_nodes(tree->left);
		counter = counter + binary_tree_nodes(tree->right);
	}
	return (counter);
}
