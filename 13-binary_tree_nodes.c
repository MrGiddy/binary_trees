#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least 1 child
 * @tree: A pointer to the root node of the tree to count nodes
 *
 * Return: 0 if `tree` is NULL, number of 1-child nodes otherwise
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);

	nodes += (tree->left || tree->right) ? 1 : 0;
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
