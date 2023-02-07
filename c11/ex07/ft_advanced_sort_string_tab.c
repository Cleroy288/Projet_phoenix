
void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		j;
	int		end;
	char	*tmp;

	end = 0;
	while (end == 0)
	{
		end = 1;
		j = 0;
		while (tab[++j + 1])
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				end = 0;
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}

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

#include <stdio.h>
int	main(int argc, char **argv)
{
	int		i;

	ft_advanced_sort_string_tab(argv, ft_strcmp);
	i = 1;
	while (i < argc)
		printf("%s\n", argv[i++]);
}

