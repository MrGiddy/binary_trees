# include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size
 *
 * Return: 0 if `tree` is NULL, number of nodes otherwise
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size, left_size, right_size;

	if (!tree)
		return (0);

	/* Recursively count the size of left and right subtrees */
	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	size = left_size + right_size + 1;

	return (size);
}
