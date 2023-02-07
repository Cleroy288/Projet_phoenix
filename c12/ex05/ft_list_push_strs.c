#include "ft_list.h"
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

#include <stdio.h>

int main(void)
{
    char *strs[] = {"hello", "world", "this", "is", "a", "test"};
    t_list *list;

    list = ft_list_push_strs(6, strs);
    while (list)
    {
        printf("%s\n", list->data);
        list = list->next;
    }
    return 0;
}

