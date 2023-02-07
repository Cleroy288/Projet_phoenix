#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

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

t_list *ft_list_push_strs(int size, char **strs)
{
    int i = 0;
    t_list *list = NULL;
    t_list *new_elem;

    while (i < size)
    {
        new_elem = ft_create_elem(strs[i]);
        new_elem->next = list;
        list = new_elem;
        i++;
    }
    return (list);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		i++;
	}
	return (0);
}

int	main()
{
	t_list *elem1 = ft_create_elem("bonjour");
	t_list *elem2 = ft_create_elem("les");
	t_list *elem3 = ft_create_elem("gens");
	t_list *elem4 = ft_create_elem("ca va ?");

	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	elem4->next = NULL;

	t_list *result = ft_list_at(elem1, 2);
	if (result)
		printf("Element at index 2 is: %s\n", result->data);
	else
		printf("Index out of range\n");
	return 0;
}
