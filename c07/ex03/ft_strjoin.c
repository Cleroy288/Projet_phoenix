#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
if (tab == 0)
{
	tab = malloc(sizeof(char));
	*tab = 0;
	return (tab);
}*/

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;
	int		j;
	int		k;
	int		count;

	j = 0;
	k = 0;
	i = 0;
	count = 1;
	while (i < size)
		count += ft_strlen(strs[i++]) + ft_strlen(sep);
	tab = malloc(sizeof(char *) * count);
	i = -1;
	while (++i < size)
	{
		while (strs[i][j] != '\0')
			tab [k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size -1)
			tab[k++] = sep[j++];
		j = 0;
	}
	tab[k] = '\0';
	return (tab);
}

int	main(void)
{
//	int		index;
	char 	**strs;
	char 	*separator;
	char 	*result;
	int	size;

	size = 3;
	
	strs = (char **)malloc(3 * sizeof(char *));
	strs [0] = (char *)malloc(sizeof(char) * 5 + 1);
	strs [1] = (char *)malloc(sizeof(char) * 2 + 1);
	strs [2] = (char *)malloc(sizeof(char) * 7 + 1);
	strs [0] = "qui suis-je vraiment";
	strs [1] = "quand";
	strs [2] = "je ne suis plus vraiment";
	separator = " ";
	result = ft_strjoin(size, strs, separator);
	printf("%s\n", result);
}

