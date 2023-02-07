#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*ptr;

	if (begin_list)
		while (begin_list)
		{
			(*free_fct)(begin_list->data);
			ptr = begin_list->next;
			free(begin_list);
			begin_list = ptr;
		}
}

