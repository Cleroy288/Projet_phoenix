#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

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

int	ft_nvx_1(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	else if (c == '/')
		return (a / b);
	else if (c == '%')
		return (a % b);
	else if (c == '*')
		return (a * b);
	return (0);
}

void	ft_ret_ph(int a, int b, char c)
{
	if (c == '/' && ft_nvx_1(a, b, c) == 0)
	{
		write(1, "Stop : division by zero", 23);
	}
	else if (c == '%' && ft_nvx_1(a, b, c) == a)
	{
		write (1, "Stop : modulo by zero", 21);
	}
}

int	main(int ac, char **av)
{
	char	c;
	int		one;
	int		sec;
	int		res;

	one = ft_atoi(av[1]);
	sec = ft_atoi(av[3]);
	c = av[2][0];
	res = ft_nvx_1(one, sec, c);
	if (ac == 4)
	{
		if (c == '/' || c == '%')
		{
			if (sec == 0)
				ft_ret_ph(one, sec, c);
			else
				ft_putnbr(res);
		}
		else if (c == '-' || c == '+' || c == '*')
			ft_putnbr(res);
		write (1, "\n", 1);
	}
	else
		write (1, "Error : too few arguments\n", 26);
}
