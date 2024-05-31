#include "binary_trees.h"

size_t check_depth(const binary_tree_t *tree);
unsigned char check_leaves(const binary_tree_t *node);
const binary_tree_t *leaves_set(const binary_tree_t *tree);
int checking_is_pefect(const binary_tree_t *tree,
int binary_tree_is_perfect(const binary_tree_t *tree);
		size_t leaf_depth, size_t level);

/**
 * checking_is_pefect - Checks if a binary tree is perfect up certain level.
 * @tree: Pointer to the root of the binary tree.
 * @leaf_depth: The depth at which the leaves are expected be present.
 * @level: The current level being checked.
 * Return: Returns 1 if the binary tree is perfect up to the specified level
 */
int checking_is_pefect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (check_leaves(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (checking_is_pefect(tree->left, leaf_depth, level + 1) &&
		checking_is_pefect(tree->right, leaf_depth, level + 1));
}

/**
 * check_depth - Computes the depth of the given binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * Return: The depth of the binary tree. If the tree is empty, returns 0.
 */
size_t check_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + check_depth(tree->parent) : 0);
}

/**
 * leaves_set - Creates a set of leaf nodes from the given binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 * Return: Pointer to the first leaf node in the set,
 * NULL if the tree is empty.
 */
const binary_tree_t *leaves_set(const binary_tree_t *tree)
{
	if (check_leaves(tree) == 1)
		return (tree);
	return (tree->left ? leaves_set(tree->left) : leaves_set(tree->right));
}
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the binary tree.
 * Return: 1 if the binary tree is perfect, 0 otherwise.
 *         If the input tree is NULL or empty, returns 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (checking_is_pefect(tree, check_depth(leaves_set(tree)), 0));
}

/**
 * check_leaves - Checks if a given node is a leaf node in a binary tree.
 *
 * @node: Pointer to the node to be checked.
 * Return: 1 if the node is a leaf node, 0 otherwise.
 */
unsigned char check_leaves(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
