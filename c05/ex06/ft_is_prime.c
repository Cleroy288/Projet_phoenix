int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 0)
		return (0);
	while (nb % i != 0)
	{
		i++;
	}
	if ( i == nb)
		return (1);
	else
		return (0);
}

#include<stdio.h>
int	main(void)
{
	int	nb = 6;
	printf("%d\n", ft_is_prime(nb));
	return (0);
}
