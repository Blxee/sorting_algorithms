#include "sort.h"

/**
 * insert_node_at - inserts a node at a new position
 *
 * @place: the new pos
 * @node: the target node
 */
void insert_node_at(listint_t **place, listint_t *node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;

	node->next = *place;
	node->prev = (*place)->prev;

	(*place)->prev = node;

	*place = node;
}

/**
 * insertion_sort_list - sorts an array using the 'Insertion Sort' algorithm
 *
 * @list: the target list (sorted in-place)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node_1, *node_2, *next;
	int tmp;

	if (!list || !*list || !(*list)->next)
		return;

	node_1 = (*list)->next;

	while (node_1)
	{
		next = node_1->next;
		node_2 = node_1->prev;
		while (node_2)
		{
			if (node_1->n > node_2->n)
			{
				insert_node_at(&node_2->next, node_1);
				print_list(*list);
				break;
			}
			node_2 = node_2->prev;
		}
		if (!node_2)
		{ /* node_1 is min of array */
			insert_node_at(list, node_1);
			print_list(*list);
		}
		node_1 = next;
	}
}
