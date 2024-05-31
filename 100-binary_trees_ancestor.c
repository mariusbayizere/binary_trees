#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that will find the lowest
 * common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: common ancestors return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *cookies, *dicks;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	cookies = first->parent, dicks = second->parent;
	if (first == dicks || !cookies || (!cookies->parent && dicks))
		return (binary_trees_ancestor(first, dicks));
	else if (cookies == second || !dicks || (!dicks->parent && cookies))
		return (binary_trees_ancestor(cookies, second));
	return (binary_trees_ancestor(cookies, dicks));
}
