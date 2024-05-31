#include "binary_trees.h"

int del_king(bst_t *head);
/**
 * batmaniplation - function that will make success to the hight node.
 * @node: will receiving the pointer to checking tree
 * Return: success
 */
int batmaniplation(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = batmaniplation(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 * best_del - function that have remove a node from a BST tree
 * @root: will receive the pointer to root of the tree
 * @data: will receving the data
 * Return: removed data
 */
bst_t *best_del(bst_t *root, int data)
{
	int finals = 0;

	if (root == NULL)
		return (NULL);
	if (data < root->n)
		best_del(root->left, data);
	else if (data > root->n)
		best_del(root->right, data);
	else if (data == root->n)
	{
		finals = del_king(root);
		if (finals != 0)
			best_del(root->right, finals);
	}
	else
		return (NULL);
	return (root);
}


/**
 *del_king - function that will delete node depend on the of children
 *@head: will receive the pointer to node to be remove
 *Return: will returning 1 or 0
 */
int del_king(bst_t *head)
{
	int flog = 0;

	if (!head->left && !head->right)
	{
		if (head->parent->right == head)
			head->parent->right = NULL;
		else
			head->parent->left = NULL;
		free(head);
		return (0);
	}
	else if ((!head->left && head->right) || (!head->right && head->left))
	{
		if (!head->left)
		{
			if (head->parent->right == head)
				head->parent->right = head->right;
			else
				head->parent->left = head->right;
			head->right->parent = head->parent;
		}
		if (!head->right)
		{
			if (head->parent->right == head)
				head->parent->right = head->left;
			else
				head->parent->left = head->left;
			head->left->parent = head->parent;
		}
		free(head);
		return (0);
	}
	else
	{
		flog = batmaniplation(head->right);
		head->n = flog;
		return (flog);
	}
}
/**
 * position - function that will checking balance of the AVL
 * @tree: will receing the pointer to the tree
 * Return: balanced
 */
void position(avl_t **tree)
{
	int kyle;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	position(&(*tree)->left);
	position(&(*tree)->right);
	kyle = binary_tree_balance((const binary_tree_t *)*tree);
	if (kyle > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (kyle < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * avl_remove - function that will remove a node from a AVL tree
 * @root: will receiving the pinter to the root of the tree
 * @value: will receiving the value
 * Return: value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *pyhno = (avl_t *) best_del((bst_t *) root, value);

	if (pyhno == NULL)
		return (NULL);
	position(&pyhno);
	return (pyhno);
}
