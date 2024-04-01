#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if True, 0 if False or @tree is NULL
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/* Using a queue for level-order traversal */
	binary_tree_t *queue[10000], *current;
	int front, rear;

	if (!tree)
		return (0);

	front = 0;
	rear = -1;

	/* Enqueue the root node */
	queue[++rear] = (binary_tree_t *)(tree);

	/* Perform level-order traversal */
	while (front <= rear)
	{
		current = queue[front++];

		/* If current node is not NULL */
		if (current)
		{
			queue[++rear] = current->left;
			queue[++rear] = current->right;
		}
		else
		{
			/* We don't expect any more non-null nodes */
			while (front <= rear)
			{
				current = queue[front++];
				if (current)
					return (0);
			}
		}
	}

	return (1);
}
