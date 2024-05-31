#include"binary_trees.h"
/**
 * binary_tree_leaves - function that will calculate the leaves of binary tree
 * @tree: will receive pointer to the node
 * Return:return the size of the leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree != NULL)
	{
		/*counter = counter + 1;*/
		counter += (!tree->left && !tree->right) ? 1 : 0;
		counter = counter + binary_tree_leaves(tree->left);
		counter = counter + binary_tree_leaves(tree->right);
	}
	return (counter);
}
