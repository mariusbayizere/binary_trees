#include "binary_trees.h"

/**
 * size_of_tree - function that will checking length of a binary track
 * @tree: will receive pointer tree
 * Return: return 1 or 0
 */
size_t size_of_tree(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (size_of_tree(tree->left) + size_of_tree(tree->right) + 1);
}

/**
 * heap_insert - function that will inserts a value the Max Binary Heap
 * @root: will receive double pointer to the root node.
 * @value: will receive the value to store
 * Return: return the pointer to node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *track, *heap, *zappa;
	int legnght, barrier, pain, bit, point, temp1;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	track = *root;
	legnght = size_of_tree(track);
	barrier = legnght;
	for (point = 0, pain = 1; barrier >= pain; pain *= 2, point++)
		barrier -= pain;

	for (bit = 1 << (point - 1); bit != 1; bit >>= 1)
		track = barrier & bit ? track->right : track->left;

	heap = binary_tree_node(track, value);
	barrier & 1 ? (track->right = heap) : (track->left = heap);

	zappa = heap;
	for (; zappa->parent && (zappa->n > zappa->parent->n); zappa = zappa->parent)
	{
		temp1 = zappa->n;
		zappa->n = zappa->parent->n;
		zappa->parent->n = temp1;
		heap = heap->parent;
	}
	return (heap);
}
