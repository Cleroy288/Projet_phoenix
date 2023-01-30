void	ft_rev_int_tab(int *tab, int size)
{	
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

int	ft_strlen(int *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include <stdio.h>
#include <unistd.h>

int	main()
{
	int	i;
	int	size;
	int str[] = {1, 2, 3, 4, 5, 6};
	
	i = 0;
	size = 6;
	ft_rev_int_tab(str, 6);

	while (i < size)
	{
		printf("%d", str[i]);
		i++;
	}
}
