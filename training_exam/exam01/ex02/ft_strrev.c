/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

*/
int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int	i = 0;
	int	len = 0;//ft_strlen(str) - 1;
	char	tmp;

	i = 0;
	while (str[len])
		len++;
	len = len - 1;
	while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

#include <stdio.h>

int	main()
{
	char str[] = "bonjour";
	printf("%s\n", ft_strrev(str));
}

/*
2 manières de faire, 

1 ) soit avec un ft-strlen - 1 + un swap

2 ) Soit en incrémentant len puis faire un len - 1 + un swap

Mise a part cela, on déclare comme pour un swap une variable temporaire, 
L'on ne fait que un swap jusqu'a la moitié de la string, car si nous allions jusqu'a bout les carctères 
reprendraient leurs places initiales.
=> ex (avec une string de longueur 7)
index ;	0 = 6;
	1 = 5;
	2 = 4;

maintenant la string est inversé ,l'index du milieu (3) n'a pas a etre changé. Si le processus de 
"swapping" continuait cela remetterai les char a leurs place, la string ne changerai pas.
*/
