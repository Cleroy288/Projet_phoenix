/*

Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr( char *str)
{
	write (1, str, ft_strlen(str));
}

int	is_char(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

void	adelle(char *str)
{
	int	i = 0;

	while (is_char(str[i]) == 0)
		i++;
	while (is_char(str[i]) == 1)
	{	
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		adelle(argv[1]);
		write (1, "\n", 1);
	}
	else
		write (1, "\n", 1);
}

/*
on crée la fonction is_char qui vérifie si le caractère sur le quel on est est un caractère alphabétique

sur base de celle-ci on vas dire a adelle de passer les cractères qui ne correpsondent pas a cette 
condition.

On incrémente pas après la seconde boucle while, donc le programme s'arrete 
après avoi récris le premier mot.

*/
