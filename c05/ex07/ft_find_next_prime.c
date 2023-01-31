int		ft_is_prime(int nb)
{
	int		i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (nb % i != 0)
	{
		i++;
	}
	if (i == nb)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (2);
	i = nb;
	while (!ft_is_prime(i))
	{
		i++;
	}
	return (i);
}

#include <stdio.h>
int	main(void)
{
	int	nb = 9;

	printf("%d\n", ft_find_next_prime(nb));
	return (0);
}
