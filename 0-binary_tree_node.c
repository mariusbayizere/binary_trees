#include<stdio.h>
#include<stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_node - funtion that will create binary tree
 * @parent: will receive the parameter
 * @value: will reiving the data
 * Return: pointer to node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *result;

	result = malloc(sizeof(binary_tree_t));
	if (result == NULL)
	{
		return (NULL);
	}
	else
	{
		result->n = value;
		result->left = NULL;
		result->parent = parent;
		result->right = NULL;
	}
	return (result);
}
