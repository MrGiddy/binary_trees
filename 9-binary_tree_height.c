#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure height
 *
 * Return: 0 if    `tree` is NULL, height of `tree` otherwise
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height, max_height;

	if (!tree)
		return (0);

	/* Check if the left node exists, if yes, calculate its height */
	left_height = (tree->left) ? 1 + binary_tree_height(tree->left) : 0;
	/* Check if the right child exists, if yes, calculate its height */
	right_height = (tree->right) ? 1 + binary_tree_height(tree->right) : 0;

	/* Calculate the max height between the left and right sutbrees */
	max_height = (left_height > right_height) ? left_height : right_height;

	return (max_height);
}
