/*

Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

*/

#include <stdlib.h>

int	len (int start, int end)
{
	int	len = 1;
	
	if ((start - end) < 0)
	{
		len = (start - end) * -1;
	}
	return (len + 1);
}


int	*ft_range(int start, int end)
{
	int	*tab;

	int	longueur = len(start, end);
	int	i = 1;

	tab = malloc(sizeof(int) * (longueur + 1));

	tab[0] = start;
	while (start != end)
	{
		tab[i] = start + 1;
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	int	start = -1;
	int	end = 5;
	int	res = len(start, end);
	int	*tab;

	tab = ft_range(start, end);
	int	i = 0;
	while (i < len(start, end))
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

/*

la fonction ft_range prend une fonction externe (len), len prend 2 int, start et end qui représentent
les 2 extermités. Cela est calculé avec un calcul, qui change la valeur si elle est négative.
La fonction renvoi celle-ci.

Dans la fonction ft_range, la fonction len calcule la longueur entre start et end, on alloue cette taille a un 
tableau de int.

le tab[0] est initialisé a start, par la suite on rentre dans une boucle.Sur base se celle ci on alloue
des valeurs dans chque case du tableau.

On met un '\0' sur la fin de la string, et on renovi la chaine.



*/
