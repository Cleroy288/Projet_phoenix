#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int	main()
{

	t_list	*list;
	t_list	*elem1 = ft_create_elem("element 1");
	t_list	*elem2 = ft_create_elem("element 6");
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


	ft_list_sort(&list, cmp);
	while (list)
	{
		printf("%s\n", list->data);
        	list = list->next;
	}
	return (0);

/*
	char str[] = "bonjour";
	char str2[] = "bonjour";

	printf("%d\n", cmp(elem1->data, elem1->data));
*/
}
