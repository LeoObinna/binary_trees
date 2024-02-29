#include "binary_trees.h"

/**
 * tree_size - Measures the sum of heights of a binary tree
 * @tree: The pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t lheight = 0;
	size_t rheight = 0;

	if (!tree)
		return (0);

	if (tree->left)
		lheight = 1 + tree_size(tree->left);

	if (tree->right)
		rheight = 1 + tree_size(tree->right);

	return (lheight + rheight);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: The pointer to the root node of the heap to convert
 * @size: The address to store the size of the array
 *
 * Return: Pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}
