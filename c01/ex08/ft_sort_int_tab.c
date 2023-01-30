/*

Je vous présente ici 2 manieres de faire le ft_sort_int_tab, voyez la quel vous plait le plus.

;)

*/

/*
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size -1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
		i++;
		}
		j++;
	}
}
*/

int	ft_comp(int a, int b)
{
	return (a - b);

}
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		if (ft_comp(tab[i] , tab[i + 1]) < 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
		}
		i++;
	}
	if (tab[0] > tab[size - 1])
	{
		temp = tab[0];
		tab[0] = tab[size - 1];
		tab[size - 1] = temp;
	}
}

#include <stdio.h>
int		main(void)
{
	int tab[9] = {30,5,2,3,4,8,16,20,24};
	ft_sort_int_tab(tab, 9);
	for(int i = 0; i < 9; i++)
	{
		printf("%d ", tab[i]); 
	}
}/
