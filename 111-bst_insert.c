#include "binary_trees.h"

/**
 * bst_insert - This function will insert value to the Binary Search Tree.
 * @tree: will receiving double pointer to root node of binary tree the value.
 * @value: will receiving value to store the node to be inserted.
 * Return: return pointer to the created node.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp2;
	bst_t *temp1;

	if (tree != NULL)
	{
		temp1 = *tree;
		if (temp1 == NULL)
		{
			temp2 = binary_tree_node(temp1, value);
			if (temp2 == NULL)
				return (NULL);
			return (*tree = temp2);
		}
		if (value < temp1->n)
		{
			if (temp1->left != NULL)
				return (bst_insert(&temp1->left, value));
			temp2 = binary_tree_node(temp1, value);
			if (temp2 == NULL)
				return (NULL);
			return (temp1->left = temp2);
		}
		if (value > temp1->n)
		{
			if (temp1->right != NULL)
				return (bst_insert(&temp1->right, value));
			temp2 = binary_tree_node(temp1, value);
			if (temp2 == NULL)
				return (NULL);
			return (temp1->right = temp2);
		}
	}
	return (NULL);
}
