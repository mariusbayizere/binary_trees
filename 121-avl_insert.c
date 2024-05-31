#include "binary_trees.h"

int Make_balance(const binary_tree_t *tree);
size_t Lenght_Hight(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *new_Average_data_rec(avl_t **tree, avl_t *parent,
		avl_t **new, int value);

/**
 * new_Average_data_rec - function that will insert new value to the AVL.
 * @tree: will receiving the double pointer to the root.
 * @parent: will receiving pointer to the parent node.
 * @new: will receive the double pointer that having the responsiblity
 * of keeping the new value.
 * @data: will receiving the value to be insert to the tree.
 * Return: returning the insert data.
 */
avl_t *new_Average_data_rec(avl_t **tree, avl_t *parent,
		avl_t **new, int data)
{
	int balance;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, data));

	if ((*tree)->n > data)
	{
		(*tree)->left = new_Average_data_rec(&(*tree)->left, *tree, new, data);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < data)
	{
		(*tree)->right = new_Average_data_rec(&(*tree)->right, *tree, new, data);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balance = Make_balance(*tree);
	if (balance > 1 && (*tree)->left->n > data)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance < -1 && (*tree)->right->n < data)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance > 1 && (*tree)->left->n < data)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && (*tree)->right->n > data)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - function that having the responsablity
 * to insert data to AVL.
 * @tree: will receiving to double pointer to point to the root.
 * @value: will receiving the data to be inserted into the AVL tree.
 * Return: returning the new value.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *pointer = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	new_Average_data_rec(tree, *tree, &pointer, value);
	return (pointer);
}

/**
 * Lenght_Hight - function that will checking the length of binary tree.
 * @tree: will receiving the pointer to the root node.
 *
 * Return: will return the length of the binary tree.
 */
size_t Lenght_Hight(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t length = 0, row = 0;

		length = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		row = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((length > row) ? length : row);
	}
	return (0);
}

/**
 * Make_balance - this function are used to checking the
 * balance factor of a binary tree.
 * @tree: will receiving pointer to the balance.
 * Return: pointer to the balance
 */
int Make_balance(const binary_tree_t *tree)
{
	return (tree != NULL ? Lenght_Hight(tree->left) -
			Lenght_Hight(tree->right) : 0);
}
