#include <stdlib.h>
#include <stdio.h>
int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;
	int	len;

	i = 0;
	len = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tab = (int *)malloc(sizeof(tab) * len);
	if (tab == NULL)
		return (-1);
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (len);
}

int		main(void)
{
	int		*range;
	int		i;

	i = 0;
	printf("return : %d\n", ft_ultimate_range(&range, -5, 50));
	while (i < 55)
	{
		printf("%d\n", range[i]);
		i++;
	}
	return (0);
}

