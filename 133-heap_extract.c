#include "binary_trees.h"
#include <stdlib.h>

void left_root_right(heap_t *tree, heap_t **node, size_t dept);
int heap_extract(heap_t **root);
size_t width_tree_(const binary_tree_t *tree);
void recursion_helps(heap_t *root);
size_t length_tree_(const heap_t *tree);

/**
 * heap_extract - function that will extract the root node from a Max Binary
 * @root: will receive double pointer to the heap root node.
 * Return: returning the extracted node
 */
int heap_extract(heap_t **root)
{
	int data;
	heap_t *nod1;
	heap_t *node;

	if (!root || !*root)
		return (0);
	nod1 = *root;
	data = nod1->n;
	if (!nod1->left && !nod1->right)
	{
		*root = NULL;
		free(nod1);
		return (data);
	}

	left_root_right(nod1, &node, length_tree_(nod1));

	nod1->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	recursion_helps(nod1);
	*root = nod1;
	return (data);
}
/**
 * width_tree_ - function that will make sum of binary tree.
 * @tree: will receiving the pointer to the node
 * Return: return the sum of binary tree
 */
size_t width_tree_(const binary_tree_t *tree)
{
	size_t node1 = 0;
	size_t node2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		node1 = 1 + width_tree_(tree->left);

	if (tree->right)
		node2 = 1 + width_tree_(tree->right);

	return (node1 + node2);
}

/**
 * left_root_right - function that will make  through a binary tree
 * @tree: will receive pointer to the root node of the tree
 * @node: will be receive last note in the tree Traverses
 * @dept: will receving the hight
 * Return: return the void
 */
void left_root_right(heap_t *tree, heap_t **node, size_t dept)
{
	if (!tree)
		return;

	if (!dept)
		*node = tree;
	dept--;

	left_root_right(tree->left, node, dept);
	left_root_right(tree->right, node, dept);
}


/**
 * length_tree_ - function that will make height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: returning the length of binary tree
 */
size_t length_tree_(const heap_t *tree)
{
	size_t node1 = 0;
	size_t node2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		node1 = 1 + length_tree_(tree->left);

	if (tree->right)
		node2 = 1 + length_tree_(tree->right);

	if (node1 > node2)
		return (node1);
	return (node2);
}

/**
 * recursion_helps - function that will make max binary heap
 * @root: will receive pointer to binary heap
 * Return: return the root to node
 */
void recursion_helps(heap_t *root)
{
	int data;
	heap_t *nod1, *nod2;

	if (!root)
		return;

	nod1 = root;

	while (1)
	{
		if (!nod1->left)
			break;
		if (!nod1->right)
			nod2 = nod1->left;
		else
		{
			if (nod1->left->n > nod1->right->n)
				nod2 = nod1->left;
			else
				nod2 = nod1->right;
		}
		if (nod1->n > nod2->n)
			break;
		data = nod1->n;
		nod1->n = nod2->n;
		nod2->n = data;
		nod1 = nod2;
	}
}

