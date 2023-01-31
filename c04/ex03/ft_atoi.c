
int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	int	test;
	if (ac == 2)
	{
		test = ft_atoi(av[1]);
		printf("résultat: %d\n" ,test);
	}
	return (0);
}
