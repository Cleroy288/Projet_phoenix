/*

Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$

*/

void	rot_13(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'M' || str[i] >= 'a' && str[i] <= 'm')
			str[i] = str[i] + 13;
		else if (str[i] >= 'N' && str[i] <= 'Z' || str[i] >= 'n' && str[i] <= 'z')
			str[i] = str[i] - 13;
		i++;
	}
}

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	while (argv[1][i])
		i++;
	if (argc == 2)
	{
		rot_13(argv[1]);
		write (1, argv[1], i);
	}
	else
		write (1, "\n", 1);
}

/*
en fonction de quel lettre est traitée il faut soit ajouter 13 ou retirer 13.

Si vous ne faites que ajouter 13, sur certaine lettre vous accédrez a de caratères autre que des lettres.

Ce qui n'est pas le but.

*/
