#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	current = *begin_list1;
	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
	{
		current = *begin_list1;
		while (current->next)
			current = current->next;
		current->next = begin_list2;
	}
}

t_list	*ft_create_elem(void *data)
{
	t_list	*created;

	created = NULL;
	created = malloc(sizeof(t_list));
	if (created)
	{
		created->data = data;
		created->next = NULL;
	}
	return (created);
}

int	main()
{
	
	t_list	*list;
	t_list	*elem1 = ft_create_elem("element 1");
	t_list	*elem2 = ft_create_elem("element 2");
	t_list	*elem3 = ft_create_elem("element 3");

	t_list	*list2;
	t_list	*elem4 = ft_create_elem("element 4");
	t_list	*elem5 = ft_create_elem("element 5");

	list = elem1;
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = NULL;

	list2 = elem4;
	elem4->next = elem5;
	elem5->next = NULL;

	ft_list_merge(&list, list2);
	while (list)
	{
		printf("%s\n", list->data);
        	list = list->next;
	}
	return (0);

}
