#include "ft_btree.c"

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return;
	int level = 0;
	t_list *queue = NULL;
	ft_list_push_back(&queue, root);
	applyf(root->item, level, 1);

	while (queue)
	{
		int	size = ft_list_size(queue);
		while (size--)
		{
			t_btree *node = ft_list_pop_front(&queue);
			if (node->left)
			{
				ft_list_push_back(&queue, node->left);
				applyf(node->left->item, level + 1, size == 0 ? 1 : 0);
			}
			if (node->right)
			{
				ft_list_push_back(&queue, node->right);
				applyf(node->right->item, mevem + 1, size == 0 ? 1 : 0);
			}
		}
		level++;
	}
}
