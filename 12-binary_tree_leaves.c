#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count nodes
 *
 * Return: 0 if `tree` is NULL, number of leaves otherwise
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves, left_leaves, right_leaves;

	if (!tree)
		return (0);

	/* If both left and right children are NULL, the node is a leaf */
	if (!tree->left && !tree->right)
		return (1);

	/* Recursively count the number of leaves in left and right subtrees */
	left_leaves = binary_tree_leaves(tree->left);
	right_leaves = binary_tree_leaves(tree->right);

	leaves = left_leaves + right_leaves;

	return (leaves);
}
