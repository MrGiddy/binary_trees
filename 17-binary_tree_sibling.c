#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: NULL if no sibling or node or parent is NULL, sibling otherwise
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;

	if (parent->left && parent->left != node)
		return (parent->left);

	if (parent->right && parent->right != node)
		return (parent->right);

	/* If node has no sibling, return NULL */
	return (NULL);
}
