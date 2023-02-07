#include "ft_list.h"

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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*push;

	if (*begin_list)
	{
		push = ft_create_elem(data);
		push->next = *begin_list;
		*begin_list = push;
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int(*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_list_sort(begin_list, cmp);
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

	t_list	*temp = list;
	ft_sorted_list_insert(&temp, "element 6", cmp);
        while (temp)
        {
                printf("%s\n", temp->data);
                temp = temp->next;
        }
        return (0);
}
