
int	ft_any(char **tab, int(*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft(char *str)
{
	if (*str == 'A')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char	**array;
	int	i;

	i = 0;
	array = malloc(sizeof(char*) * 3);
	array[0] = "A";
	array[1] = "Z";
	array[2] = NULL;
	while (i < 3)
	{
		printf("%d\n", ft_any(&array[i], ft));
		i++;
	}
}
*/
