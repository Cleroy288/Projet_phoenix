/*
celui-ci est le bon, preésente celui-la
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "ft_list.h"

typedef struct    s_list
{
    int           data;
    struct s_list *next;
}                 t_list;


void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	current = *begin_list;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

int     main()
{
    t_list *elem1, *elem2, *elem3, *elem4, *begin;

    elem1 = (t_list *)malloc(sizeof(t_list));
    elem2 = (t_list *)malloc(sizeof(t_list));
    elem3 = (t_list *)malloc(sizeof(t_list));
    elem4 = (t_list *)malloc(sizeof(t_list));

    elem1->data = 1;
    elem2->data = 2;
    elem3->data = 3;
    elem4->data = 4;

    begin = elem1;
    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    elem4->next = NULL;

    ft_list_reverse(&begin);

    while (begin)
    {
        printf("%d\n", begin->data);
        begin = begin->next;
    }
    return 0;
}
