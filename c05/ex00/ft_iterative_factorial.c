
int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	if (nb == 0)
		return (1);
	/*
	if (nb == 1)
		return (0);
	*/
	if ((nb <= 0) || (nb > 12) || (nb == 1))
		return (0);
	while (i <= nb)
	{
		res = i * res;
		i++;
	}
	return (res);
}

#include<stdio.h>
int	main(void)
{
	int	nb;

	nb = 12;
	printf("%d\n", ft_iterative_factorial(nb));
	return(0);
}
