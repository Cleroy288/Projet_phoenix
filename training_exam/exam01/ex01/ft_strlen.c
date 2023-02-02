/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);
*/

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include <stdio.h>
int	main()
{
	char str[] = "bonjour";
	printf("%d\n", ft_strlen(str));
}

/*
Le int (i) est incrémenté grace a la boucle while tant que str[i] n'est pas égal a '\0'
LA syntaxe while (str[i]) signifie tant que str[i] n'est pas égal a '\0' , incrémente i (i++).
Le i sera donc incrémenté jusqu'a ce que la chaine de carcatère str sois terminé (égal a  '\0')
*/
