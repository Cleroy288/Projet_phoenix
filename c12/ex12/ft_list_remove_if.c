#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

//Bon ben du coup t'en as eu marre, on fera ca plus tard. La fonction principale est sesné etre bonne.

/*
typedef struct s_list
{
    int data;
    struct s_list *next;
} t_list;
*/
/*
int cmp(int a, int b)
{
    return (a == b);
}

void free_fct(int *data)
{
    free(data);
}

//void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(int, int), void (*free_fct)(int*));
*/
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*prev;
	t_list	*tmp;

	current = *begin_list;
	prev = NULL;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			tmp = current;
			if (prev)
				prev->next = current->next;
			else
				*begin_list = current->next;
			current = current->next;
			(*free_fct)(tmp->data);
			free(tmp);
		}
		else
		{
			prev = current;
			current = current->next;
        	}
	}
}

/*
int	main(void)
{
	t_list	*list;
	t_list	*elem1 = ft_create_elem("element 1");
	t_list	*elem2 = ft_create_elem("element 2");
	t_list	*elem3 = ft_create_elem("element 3");
	t_list	*data_ref = ft_create_elem("element 2");

	list = elem1;
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = NULL;

	int	a = 1;
	int	b = 2;

	ft_list_remove_if(list ,data_ref->data, (*cmp)(a, b), (*free_fct)(elem1));
	return (0);
}
*/

