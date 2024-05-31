#include "binary_trees.h"

bst_t *remove_binary_tree(bst_t *root, bst_t *node);
bst_t *get_writing(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);
bst_t *recurse_binary_remove(bst_t *root, bst_t *node, int value);

/**
 * recurse_binary_remove - Removes a node from a binary.
 * @root: will receive pointer to the root node of the BST.
 * @node: will receive pointer to the current node in the BST.
 * @value: will receive The value to remove from the BST.
 * Return: root to the node
 */
bst_t *recurse_binary_remove(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (remove_binary_tree(root, node));
		if (node->n > value)
			return (recurse_binary_remove(root, node->left, value));
		return (recurse_binary_remove(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - this function will remove node from a binary search tree.
 * @root: will receive pointer to the root node of the BST.
 * @value: will receive value to remove in the BST.
 * Return: pointer to root.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (recurse_binary_remove(root, root, value));
}

/**
 * remove_binary_tree - this function will delete a node from a
 * binary search tree.
 * @root: will receive pointer to the root node of the BST.
 * @node: will receive pointer to the node to delete from the BST.
 * Return: pointer to root node.
 */
bst_t *remove_binary_tree(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent;
	bst_t *ptr1 = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	ptr1 = get_writing(node->right);
	node->n = ptr1->n;

	return (remove_binary_tree(root, ptr1));
}

/**
 * get_writing - this function will return of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 * Return: pointer to the root
 */
bst_t *get_writing(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
