#include "ft_list.h"

void	ft_list_reverse_fun(t_list **begin_list)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

t_list  *ft_create_elem(void *data)
{
        t_list  *created;

        created = NULL;
        created = malloc(sizeof(t_list));
        if (created)
        {
                created->data = data;
                created->next = NULL;
        }
        return (created);
}

#include <stdio.h>

int     main()
{

        t_list  *list;
        t_list  *elem1 = ft_create_elem("element 1");
        t_list  *elem2 = ft_create_elem("element 2");
        t_list  *elem3 = ft_create_elem("element 3");

        list = elem1;
        elem1->next = elem2;
        elem2->next = elem3;
        elem3->next = NULL;

        ft_list_reverse_fun(&list);
	t_list	*temp = list;
        while (temp)
        {
                printf("%s\n", temp->data);
                temp = temp->next;
        }
        return (0);
}
