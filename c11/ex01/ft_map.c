#include <stdlib.h>
int	ft_mul(int a)
{
	return (a * 2);
}

int	*ft_map(int *tab, int lenght, int(*f)(int))
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * lenght);
	if (!res)
		return (NULL);
	while (i++ < lenght)
		res[i] = (*f)(tab[i]);
	return (res);
}

/*
#include <stdio.h>

int main (void)
{
	int	i;
	int *tab;
	int length;
	int *res;

	tab = malloc(length * sizeof(int));
	length = 10;
	i = 0;
	while (i < length)
	{
		tab[i] = i;
		i++;
	}
	res = ft_map(tab, length, &ft_mul);
	i = 0;
	while ( i < length)
	{
		printf( "%i", res[i]);
		i++;
	}
}
*/
