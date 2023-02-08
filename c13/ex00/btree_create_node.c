#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void	*item)
{
	t_btree	*new_node;

	new_node = (t_btree*)malloc(sizeof(t_btree));
	if (new_node)
	{
		new_node->item = item;
		new_node->left = 0;
		new_node->right = 0;
	}
	return (new_node);
}

#include <stdio.h>

int	main()
{
	t_btree	*root;
	int	item = 42;

	root = btree_create_node(&item);
	if (root)
	{
		printf("node created with item value : %d\n", *((int*)root->item));
		free(root);
	}
	return (0);
}
