#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root of the tree to check
 *
 * Return: 0 if `tree` is NULL or false, 1 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* If the current node has no children, it is a leaf node */
	/* and the tree is full */
	if (!tree->left && !tree->right)
		return (1);

	/* If the current node has both children, recursively check */
	/* if the subtrees are full */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If the current node has only one child, the tree is not full */
	return (0);
}
