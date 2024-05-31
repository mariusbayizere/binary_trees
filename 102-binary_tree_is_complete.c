#include "binary_trees.h"

void delete_queque(levelorder_queue_t *head);
levelorder_queue_t *new_node(binary_tree_t *node);
void insrert_into_stack(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **temp);
int binary_tree_is_complete(const binary_tree_t *tree);
void Remove_element_in(levelorder_queue_t **head);

/**
 * new_node - this function will create  ptr levelorder_queue_t node.
 * @node: will receive binary tree node for node.
 * Return: void
 */
levelorder_queue_t *new_node(binary_tree_t *node)
{
	levelorder_queue_t *ptr;

	ptr = malloc(sizeof(levelorder_queue_t));
	if (ptr == NULL)
		return (NULL);

	ptr->node = node;
	ptr->next = NULL;

	return (ptr);
}

/**
 * delete_queque - this function will delete list on queue.
 * @head: will receive the head pointer.
 * Return: void
 */
void delete_queque(levelorder_queue_t *head)
{
	levelorder_queue_t *ptr1;

	while (head != NULL)
	{
		ptr1 = head->next;
		free(head);
		head = ptr1;
	}
}

/**
 * insrert_into_stack - this function will inserting data on the stack queue.
 * @node: will receiving the pointer of the node.
 * @head: will receiving the head double pointer.
 * @temp: will receiving the temp as double pointer.
 * Return: void
 */
void insrert_into_stack(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **temp)
{
	levelorder_queue_t *ptr;

	ptr = new_node(node);
	if (ptr == NULL)
	{
		delete_queque(head);
		exit(1);
	}
	(*temp)->next = ptr;
	*temp = ptr;
}

/**
 * Remove_element_in - this function will  head of on the list queue.
 * @head: will receiving  double pointer to head of the queue.
 * Return: void
 */
void Remove_element_in(levelorder_queue_t **head)
{
	levelorder_queue_t *ptr1;

	ptr1 = (*head)->next;
	free(*head);
	*head = ptr1;
}

/**
 * binary_tree_is_complete - this function that will checking
 * binary tree is complete.
 * @tree: will receiving tree of the node.
 * Return: tree of pointer
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head;
	levelorder_queue_t *temp;
	unsigned char flok1 = 0;

	if (tree == NULL)
		return (0);

	head = temp = new_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flok1 == 1)
			{
				delete_queque(head);
				return (0);
			}
			insrert_into_stack(head->node->left, head, &temp);
		}
		else
			flok1 = 1;
		if (head->node->right != NULL)
		{
			if (flok1 == 1)
			{
				delete_queque(head);
				return (0);
			}
			insrert_into_stack(head->node->right, head, &temp);
		}
		else
			flok1 = 1;
		Remove_element_in(&head);
	}
	return (1);
}
