int	ft_strcmp(char *s1, char *s2)
{
	int	val1;
	int	val2;
	int	i;
	int	j;

	i = 0;
	j = 0;
	val1 = 0;
	val2 = 0;
	while (s1[i])
	{
		val1 += s1[i];
		i++;
	}
	while (s2[j])
	{
		val2 += s2[j];
		j++;
	}
	return (val1 - val2);
}

void	ft_sort_string_tab(char **tab)
{
	char	*tmp;
	int	i;
	int	end;

	while (end == 0)
	{
		i = 1;
		end = 1;
		while (tab[i + 1] != '\0')
		{
			if (ft_strcmp(tab[i], tab[i + 1]) < 0)
			{
				end = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		i++;
		}
	}
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;

	ft_sort_string_tab(argv);
	i = 1;
	while (i <= argc)
	{
			printf("%s\n", argv[i]);
			i++;
	}
}

