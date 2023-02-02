/*

Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$

*/

void	rotone(char *str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] == 'Z' || str[i] == 'z')
			str[i] = str[i] - 25;
		else
			str[i] += 1;
		i++;
	}
}

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	while (argv[1][i])
		i++;
	rotone(argv[1]);
	write (1, argv[1], i);
}

/*
on ajoute un 1 si le caractère sur le quel on est n'est pas un Z.

Si on est sur un Z ou z on soustrait 25 pour aller jusqu'a A.

*/
