int	ft_sqrt(int nb)
{
	int	a;
	int	res;

	a = 3;
	res = 1;
	if (nb == 0)
		return (0);
	if (nb == 2)
		return (1);
	if (nb == 4)
		return (2);
	while (a != nb / a)
	{
		res = a * a;
		a++;
	}
	if ((nb % a) != 0)
		return (0);
	return (a);
}

#include <stdio.h>
int	main(void)
{
	int	nb = 25;

	printf("%d\n", ft_sqrt(nb));
	return (0);
}
