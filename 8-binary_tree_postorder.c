#include "binary_trees.h"

/**
 * binary_tree_postorder - Post-order traverses a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * The value in the node must be passed as the paramenter to `func`
 *
 * Return: Nothing
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/**
	 * Visit the left subtree
	 * Visit the right subtree
	 * Visit the root node
	*/
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
