#include "binary_trees.h"

/**
 * binary_tree_levelorder - Level-order traverses a binary tree
 * @tree: Pointer to the root node of the tree to travers
 * @func: Pointer to a function to call for each node
 * The value in the node must be passes as a parameter to func
 *
 * Return: Nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Create a queue to store nodes */
	binary_tree_t *queue[1000];
	int front, rear;
	binary_tree_t *current;

	if (!tree || !func)
		return;

	front = 0;
	rear = -1;

	/* Enqueue the root node */
	queue[++rear] = (binary_tree_t *)tree;

	while (front <= rear)
	{
		/* Dequeue a node and call func */
		current = queue[front++];
		func(current->n);

		/* Enqueue the left child if exists */
		if (current->left)
			queue[++rear] = current->left;

		/* Enqueue the right child if exists */
		if (current->right)
			queue[++rear] = current->right;
	}
}
