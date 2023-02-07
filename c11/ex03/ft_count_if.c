
int	ft_count_if(char **tab, int lenght, int(*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	while (i < lenght)
	{
		if ((*f)(tab[i]))
			count++;
		i++;
	}
	return (count);
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

int main (void)
{
	char **array;
	int	i;

	array = malloc(3 * sizeof(char *));
	array[0] = "A";
	array[1] = "Z";
	array[2] = "A";
	array[3] = "NULL";
	printf("%d\n", ft_count_if(array, 3, ft));
}
*/
