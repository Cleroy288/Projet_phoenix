#include <stdio.h>
#include "ft_list.h"

t_list	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

t_list	*ft_list_push_strs(int size, char **strs);

int		main(void)
{
	t_list	*begin;
	char	**strs;

	strs = malloc(sizeof(char*) * 5);
	strs[0] = "bite";
	strs[1] = "bute";
	strs[2] = "bate";
	strs[3] = "bote";
	strs[4] = "bete";
	begin = ft_list_push_strs(5, strs);
	while (begin)
	{
		printf("%s\n", begin->data);
		begin = begin->next;
	}
	ft_list_clear(begin, free);
//	printf("%s\n", begin->data);
	printf("bonjour");
}

