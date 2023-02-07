#include <stdio.h>
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*ptr;

	ptr = begin_list;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

int	main()
{
	t_list	elem1, elem2, elem3, elem4, *begin;

	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = 0;

	elem1.data = "1";
	elem2.data = "2";
	elem3.data = "3";
	elem4.data = "bonjour";

	printf("%s\n", ft_list_last(begin)->data);

}
