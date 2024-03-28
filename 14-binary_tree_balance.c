#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure bf
 *
 * Return: 0 if `tree` is NULL, balance factore otherwise
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
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
