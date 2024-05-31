#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

int make_HIGHT_maximun(const binary_tree_t *tree);
/**
 * binary_tree_is_heap - function that will checking the hight of tree.
 * @tree: will receiving pointer to the root node
 * Return: return 0 or 1
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int togger;

	if (!tree)
		return (0);

	togger = binary_tree_is_complete(tree);
	if (!togger)
		return (0);
	return (make_HIGHT_maximun(tree));
}

/**
 * make_HIGHT_maximun - function that will checking the
 * maximun value in binary tree
 * @tree: will receiving pointer to the root
 * Return: return the 1 or 0
 */
int make_HIGHT_maximun(const binary_tree_t *tree)
{
	int pointer1 = 1;
	int pointer2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		pointer1 = make_HIGHT_maximun(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		pointer2 = make_HIGHT_maximun(tree->right);
	}
	return (pointer1 && pointer2);
}

