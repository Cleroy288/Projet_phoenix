#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		(*f)(current->data);
		current = current->next;
	}
}

void	print_data(void *data)
{
	printf("%s\n", (char *)data);
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

int	main(void)
{
	t_list	*list;
	t_list	*elem1 = ft_create_elem("element 1");
	t_list	*elem2 = ft_create_elem("element 2");
	t_list	*elem3 = ft_create_elem("element 3");

	list = elem1;
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = NULL;

	ft_list_foreach(list, &print_data);
	return (0);
}


