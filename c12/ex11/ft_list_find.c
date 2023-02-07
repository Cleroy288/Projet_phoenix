
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		if ((*cmp)(current, data_ref) == 0)
			return (&current);
		current = current->next;
	}
}
