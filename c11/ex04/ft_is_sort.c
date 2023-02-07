/*
si la string est trié renvoyer 1, si elle ne l'est pas renvoyer 0
/////////////////////////////////////////////////////////////////////////////////////////
la fonction : si le premier est inferieur au 2eme retourner -1, renvoie 0 si ils sont égaux,
 renvoie 1 pour quoi que ce soit d'autre.
*/

#include <stdlib.h>

int	ft_strlen(int	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_sort(int *tab, int lenght, int(*f)(int, int))
{
	int	i;
	int	y;

	i = 0;
	y = ft_strlen(tab);
	while (i != y - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) == -1 && (tab[i + 1] != '\0'))
			i++;
		else if ((*f)(tab[i], tab[i + 1]) == 0 && (tab[i + 1] != '\0'))
			i++;
		else
			return (0);
	}
	if ((tab[i + 1] == '\0' && (tab[i - 1] < tab[i])))
		i++;
	else if ((tab[i + 1] == '\0' && (tab[i - 1] == tab[i])))
		i++;
	else if (i == y)
		return (1);
	else if (i != y)
		return (0);
}

int	ft_function(int a, int b)
{
	if (a == b)
		return (0);
	else if (a < b)
		return (-1);
	else
		return (1);
}
/*
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	static int tab[] = {1, 1, 1, 1, 1};
	int lenght = ft_strlen(tab);
	printf("%d\n", ft_is_sort(tab, lenght, &ft_function));
	printf("%d\n", ft_strlen(tab));
}
*/
