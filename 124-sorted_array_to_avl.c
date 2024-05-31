#include "binary_trees.h"

void make_tree_AVL(avl_t **node, int *array, size_t size, int mode);
/**
 * sorted_array_to_avl - function that will make sorting of node
 * head node and calls to create_tree
 * @array: will receiving the array input integers
 * @size: will receiving the size of array
 * Return: return the pointer to the node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;
	size_t temp;

	head = NULL;

	if (size == 0)
		return (NULL);

	temp = (size / 2);

	temp = (size % 2 == 0) ? temp - 1 : temp;

	head = binary_tree_node(head, array[temp]);

	make_tree_AVL(&head, array, temp, 1);
	make_tree_AVL(&head, array + temp + 1, (size - 1 - temp), 2);

	return (head);
}

/**
 * make_tree_AVL - function that will create the tree
 *
 * @node: will receiving the pointer to the node
 * @array: will receiving the array
 * @size: will the size of array
 * @mode: will receiving the model for add
 * Return: return void
 */
void make_tree_AVL(avl_t **node, int *array, size_t size, int mode)
{
	size_t temp;

	if (size == 0)
		return;

	temp = (size / 2);
	temp = (size % 2 == 0) ? temp - 1 : temp;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[temp]);
		make_tree_AVL(&((*node)->left), array, temp, 1);
		make_tree_AVL(&((*node)->left), array + temp + 1, (size - 1 - temp), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[temp]);
		make_tree_AVL(&((*node)->right), array, temp, 1);
		make_tree_AVL(&((*node)->right), array + temp + 1, (size - 1 - temp), 2);
	}
}
