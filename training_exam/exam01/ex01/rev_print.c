/*

Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a string and displays the string in reverse
order followed by the newline.
Its prototype is constructed like this : 
  char *ft_rev_print (char *str)
It must return its argument

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$

*/

#include <unistd.h>
char	*ft_rev_print(char *str)
{
	int	i = 0;
	int	j = 0;
	char	*tab;

	while (str[i])
		i++;
	while (i != 0)
	{
		write (1, &str[i], 1);
		i--;
	}
	write (1, &str[i], 1);
	write (1, "\n", 1);
}

#include <stdio.h>
int	main()
{
	char str[] = "bonjour";
	ft_rev_print(str);
}

/*
On parcour la liste jusqu'a la fin, par la suite l'on décremente jusqu'a 0, une fois a zéro la boucle s'arrête
Il faut donc afficher le dernier carcatère dans la string a l'endroit 0 (str[0]) pour afficher la string au
complet.
j'affiche par la suite un retour a la ligne (\n).
*/
