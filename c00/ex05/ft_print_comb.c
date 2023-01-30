/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print(int nb, int nb2, int nb3)
{
	ft_putchar(nb);
	ft_putchar(nb2);
	ft_putchar(nb3);
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	int nb;
	int nb2;
	int nb3;

	nb = 0;
	nb2 = 1;
	nb3 = 2;
	while(nb != 7)
	{
		while (nb2 != 8)
		{
			while (nb3 != 9)
			{
				ft_print(nb, nb2, nb3);
				nb3++;
			}
			nb2++;
		}
		nb++;
	}
}

int	main(int argc, const char *argv[])
{
	ft_print_comb();
	return (0);
}*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print(int i, int j, int k)
{
	ft_putchar(i);
	ft_putchar(j);
	ft_putchar(k);
	ft_putchar(',');
	ft_putchar(' ');
}


void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = '0';
	j = '1';
	k = '2';

	while (i < ('6' + 1))
	{
		while (j < ('7' + 1))
		{
			while (k < ('8' + 1))
			{
				ft_print( i, j, k);
				k++;
			}
			k = ++j + 1;
		}
		j = ++i ;
	}
}

int main(int argc, const char *argv[])
{
	ft_print_comb();
	return 0;
}
