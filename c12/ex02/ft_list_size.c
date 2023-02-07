#include "ft_list.h"
#include <stdio.h>

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*list;

	list = begin_list;
	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

int	main()
{
	t_list elem1, elem2, elem3, *begin;

	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = 0;

	elem1.data = "toto";
	elem2.data = "tata";
	elem3.data = "tutu";
	printf("%d\n", ft_list_size(&begin));
}
