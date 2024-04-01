#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor or two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, NULL if not found
*/
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first,
	const binary_tree_t *second
)
{
	const binary_tree_t *temp, *ancestor;

	if (!first || !second)
		return (NULL);

	/* Check if second is an ancestor of first */
	temp = first;
	while (temp != NULL)
	{
		if (temp == second)
			return ((binary_tree_t *)second);
		temp = temp->parent;
	}

	/* Check if first is an ancestor of second */
	temp = second;
	while (temp != NULL)
	{
		if (temp == first)
			return ((binary_tree_t *)first);
		temp = temp->parent;
	}

	/* Traverse upwards from both nodes until common ancestor is found */
	ancestor = first;
	while (ancestor != NULL)
	{
		temp = second;
		while (temp != NULL)
		{
			if (ancestor == temp)
				return ((binary_tree_t *)ancestor);
			temp = temp->parent;
		}
		ancestor = ancestor->parent;
	}

	/* If no common ancestor is found, return NULL */
	return (NULL);
}
