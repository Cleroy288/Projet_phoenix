
int	ft_strcmp(char *s1, char *s2)
{
	int	b;
	int	a;
	int	tmp;

	a = 0;
	b = 0;
	while (*s1++)
	{
		tmp = *s1;
		a = a + tmp;
	}
	while (*s2++)
	{
		tmp = *s2;
		b = b + tmp;
	}
	return (a - b);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		end;
	char	*tmp;	

	end = 0;
	while (end == 0)
	{
		end = 1;
		i = 0;
		while (tab[++i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				end = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
	}
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int		i;

	ft_sort_string_tab(argv);
	i = 1;
	while (i < argc)
		printf("%s\n", argv[i++]);
}

