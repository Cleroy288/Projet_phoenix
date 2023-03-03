#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
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

int	ft_nb_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], charset) == 1)
				i++;
		if (str[i] && ft_is_sep(str[i], charset) == 0)
			count++;
		while (str[i] && ft_is_sep(str[i], charset) == 0)
			i++;
	}
	return (count);
}

int	ft_len_word(char *str, char *charset, int pos)
{
	int	count;

	count = 0;
	while (str[pos] != '\0' && ft_is_sep(str[pos], charset) == 1)
		pos++;
	if (str[pos] != '\0' && ft_is_sep(str[pos], charset) == 0)
	{
		while (str[pos] != '\0' && ft_is_sep(str[pos], charset) == 0)
		{
			count++;
			pos++;
		}
	}
	return (count);
}

char	*ft_dup(char *str, char *charset, int pos)
{
	int		j;
	char	*tab;

	j = 0;
	while (str[pos] && ft_is_sep(str[pos], charset) == 1)
		pos++;
	tab = malloc(sizeof(char) * (ft_len_word(str, charset, pos) + 1));
	if (!tab)
		return (0);
	while (str[pos] && ft_is_sep(str[pos], charset) == 0)
	{
		tab[j] = str[pos];
		j++;
		pos++;
	}
	tab[j] = '\0';
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char			**tab2;
	long int		i;
	long int		j;

	i = 0;
	j = 0;
	if ((!str) || (!charset))
		return (0);
	tab2 = malloc(sizeof(char *) * (ft_nb_word(str, charset) + 1));
	if (!tab2)
		return (0);
	while (str[i] && j <= ft_nb_word(str, charset) - 1)
	{
		while (str[i] && ft_is_sep(str[i], charset) == 1)
			i++;
		if (ft_is_sep(str[i], charset) == 0)
			tab2[j++] = ft_dup(str, charset, i);
		while (str[i] && ft_is_sep(str[i], charset) == 0)
			i++;
	}
	tab2[j] = NULL;
	return (tab2);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	char **tab;

	if (argc == 3)
	{
		tab = ft_split(argv[1], argv[2]);
		int i = 0;
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
}
