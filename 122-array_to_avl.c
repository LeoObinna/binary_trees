#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: A pointer to the root node of the created AVL tree, NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, jindex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (jindex = 0; jindex < index; jindex++)
		{
			if (array[jindex] == array[index])
				break;
		}
		if (jindex == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
