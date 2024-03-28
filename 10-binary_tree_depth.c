#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: 0 if `tree` is null, depth of node otherwise
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth;

	if (!tree)
		return (0);

	node_depth = 0;
	while (tree->parent)
	{
		node_depth++;
		tree = tree->parent;
	}

	return (node_depth);
}
