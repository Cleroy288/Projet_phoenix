#include <stdio.h>
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i] || c == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	len_of_word(char *str, char *charset, int pos)
{
	int	count;

	count = 0;
	while (is_sep(str[pos], charset) == 1)
		pos++;
	if (is_sep(str[pos], charset) == 0)
	{
		while (is_sep(str[pos], charset) == 0)
		{
			count++;
			pos++;
		}
	}
	return (count);
}

int	numb_of_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && is_sep(str[i + 1], charset) == 1 && is_sep(str[i], charset) == 0)
			count++;
		i++;
	}
	return (count);
}


char	**ft_split(char *str, char *charset)
{
	char **tab;
	int	i;
	int	j;
	int	e;
	int	count;

	i = 0;
	j = 0;
	count = numb_of_word(str, charset);
	tab = malloc(sizeof(char *) * count + 1);
	while (str[i])
	{
		e = 0;
		while (is_sep(str[i], charset) == 1)
			i++;
		if (is_sep(str[i], charset) == 0)
			tab[j] = malloc(sizeof(char) * len_of_word(str, charset, i) + 1);
		while (is_sep(str[i], charset) == 0)
			tab[j][e++] = str[i++];
		tab[j][e] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}


#include <stdio.h>
int	main(int argc, char **argv)
{
	int		index;
	char	**split;
	(void)	argc;
	split = ft_split(argv[1], argv[2]);
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
}
