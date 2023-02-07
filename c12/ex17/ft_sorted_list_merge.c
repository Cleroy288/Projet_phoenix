#include "ft_list.h"

/*
 écrire la fonction ft_sorted_list_merge qui intègre les éléments d’une liste triée begin2 dans une autre liste triée begin1, de sorte que la liste begin1 reste triée par ordre croissant.
*/

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

int	cmp(char *str, char *str2)
{
	int	i;
	int	j;
	int	tmp1;
	int	tmp2;

	i = 0;
	j = 0;
	tmp1 = 0;
	tmp2 = 0;
	if (str == NULL)
		tmp1 = 0;
	else if (str2 == NULL)
		tmp2 = 0;
	while (str2[i])
	{
		tmp1 = str[i] + tmp1;
		tmp2 = str2[j] + tmp2;
		i++;
		j++;
	}
	return (tmp1 - tmp2);
}

void	ft_list_swap(t_list *list)
{
	void	*data;

	data = list->data;
	list->data = list->next->data;
	list->next->data = data;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*a;
	t_list	*b;

	a = *begin_list;
	while (a != NULL)
	{
		b = *begin_list;
		while (b->next != NULL)
		{
			if ((*cmp)(b->data, b->next->data) > 0)
				ft_list_swap(b);
			b = b->next;
		}
		a = a->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
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

#include <stdio.h>

int     main()
{

        t_list  *list;
        t_list  *elem1 = ft_create_elem("element 6");
        t_list  *elem2 = ft_create_elem("element 2");
        t_list  *elem3 = ft_create_elem("element 3");

        list = elem1;
        elem1->next = elem2;
        elem2->next = elem3;
        elem3->next = NULL;

	t_list	*list2;
	t_list	*elem4 = ft_create_elem("element 4");
	t_list	*elem5 = ft_create_elem("element 1");
	t_list	*elem6 = ft_create_elem("element 5");

	list2 = elem4;
	elem4->next = elem5;
	elem5->next = elem6;
	elem6->next = NULL;

	ft_sorted_list_merge(&list, list2, cmp);
        while (list)
        {
                printf("%s\n", list->data);
                list = list->next;
        }
        return (0);
}
