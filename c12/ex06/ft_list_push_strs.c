#include "ft_list.h"

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
