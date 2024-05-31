#include "binary_trees.h"

void delete_binary_tree(ptr_nod1 *head);
ptr_nod1 *extending_pragram(ptr_nod1 *head, const binary_tree_t *fadul);
ptr_nod1 *taking_parent_node(ptr_nod1 *head, const binary_tree_t *map);
void recuresion_level(ptr_nod1 *head, void (*func)(int));

/**
 * recuresion_level - this function Call func all
 * node at each level on program.
 * @head: will receive pointer to head of linked.
 * @func: will receive pointer to a function to
 * call on the node.
 * Return: void
 */
void recuresion_level(ptr_nod1 *head, void (*func)(int))
{
	ptr_nod1 *pian = NULL;
	ptr_nod1 *ccn1 = NULL;

	if (!head)
		return;
	for (ccn1 = head; ccn1 != NULL; ccn1 = ccn1->next)
	{
		func(ccn1->node->n);
		pian = taking_parent_node(pian, ccn1->node);
	}
	recuresion_level(pian, func);
	delete_binary_tree(pian);
}

/**
 * delete_binary_tree - delete all the node in a linked list
 * @head: will receiving pointer to the head of linked list
 * Return: return void
 */
void delete_binary_tree(ptr_nod1 *head)
{
	ptr_nod1 *temp = NULL;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * taking_parent_node - this function will extending_pragram
 * pian of map to linked list.
 * @head: will recieve the pointer to head of linked list appended.
 * @map: will recevive pointer to node on the pian we want to add.
 * Return: will returning pointer to head of linked list.
 */
ptr_nod1 *taking_parent_node(ptr_nod1 *head, const binary_tree_t *map)
{
	if (map->left)
		head = extending_pragram(head, map->left);
	if (map->right)
		head = extending_pragram(head, map->right);
	return (head);
}

/**
 * binary_tree_levelorder - Goes through a binary tree
 *                          using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ptr_nod1 *pian = NULL;

	func(tree->n);
	pian = taking_parent_node(pian, tree);
	recuresion_level(pian, func);

	delete_binary_tree(pian);
}

/**
 * extending_pragram - adds a new node at the end of a linkedlist
 * @head: will receive the pointer to head of linked list
 * @fadul: will receive the binary tree node to extending_pragram
 * Return: will return the pointer to head
 */
ptr_nod1 *extending_pragram(ptr_nod1 *head, const binary_tree_t *fadul)
{
	ptr_nod1 *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = fadul;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}
