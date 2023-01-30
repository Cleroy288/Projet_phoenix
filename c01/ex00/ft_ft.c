void	ft_ft(int *nbr)
{
	*nbr = 42;
}

#include <stdio.h>
int	main()
{
	int	nbr;

	ft_ft(&nbr);
	printf("%d\n", nbr);
}
