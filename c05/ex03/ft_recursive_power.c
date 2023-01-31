int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 1)
		return (nb * ft_recursive_power(nb, --power));
	return (nb);
}

#include <stdio.h>
int	main(void)
{
	int	nb;
	int	power;

	nb = 7;
	power = 3;
	printf("%d\n", ft_recursive_power(nb, power));
}
