#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is balanced, 0 if not or tree is NULL
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t bal_factor;

	/* A binary tree is perfect if it is full and balanced */

	if (!tree)
		return (0);

	/* If bal_factor is 0, tree is balanced */
	bal_factor = binary_tree_height(tree->left) - binary_tree_height(tree->right);

	/* Check if tree is perfect or not */
	if (bal_factor == 0 && binary_tree_is_full(tree))
	{
		return (1);
	}
	else
	{
		return (0);
	}

	/* Recursively check if both the left and right subtrees are perfect */
	return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
}

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

	left_height = (tree->left) ? 1 + binary_tree_height(tree->left) : 1;
	right_height = (tree->right) ? 1 + binary_tree_height(tree->right) : 1;

	max_height = (left_height > right_height) ? left_height : right_height;

	return (max_height);
}

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
