#include "binary_trees.h"

size_t func_size_binary(const binary_tree_t *tree);
/**
 * heap_to_sorted_array - function that will Convert Binary Max Heap
 * to a sorted array of integer
 * @heap: will receive pointer to the root node convert
 * @size: will receiving size of array
 * Return: return pointer to array.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int x;
	int *y = NULL;

	if (!heap || !size)
		return (NULL);

	*size = func_size_binary(heap) + 1;

	y = malloc(sizeof(int) * (*size));

	if (!y)
		return (NULL);

	for (x = 0; heap; x++)
		y[x] = heap_extract(&heap);

	return (y);
}
/**
 * func_size_binary - function that will make the sum of height in binary tree
 * @tree: will receiving pointer to the root node of the tree to height
 * Return: return the length of hight.
 */
size_t func_size_binary(const binary_tree_t *tree)
{
	size_t hagal = 0;
	size_t dannel = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hagal = 1 + func_size_binary(tree->left);

	if (tree->right)
		dannel = 1 + func_size_binary(tree->right);

	return (hagal + dannel);
}
