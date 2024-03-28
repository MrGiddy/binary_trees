#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to uncle node, NULL if node is NULL or uncle node DNE
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle, *parent;

	if (!node || !node->parent)
		return (NULL);

	/* The sibling of the parent is the uncle */
	parent = node->parent;
	uncle = binary_tree_sibling(parent);
	if (!uncle)
		return (NULL);
	return (uncle);
}

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
