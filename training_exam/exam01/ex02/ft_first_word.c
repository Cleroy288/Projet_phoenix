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

int	main(int argc, char **argv)
{
	int	i = ft_strlen(argv[1]);
	int	j = ft_strlen(argv[2]);
	if (argc == 3)
	{
		ft_putstr(argv[1]);// 1)
		write (1, "\n", 1);
		write (1, argv[2], j);// 2
	}
}

/*
il y a 2 facons de faire ici,

1 ) on crée une fonction putstr et on affiche argv[1].
	-putstr utilise strlen pour définir une longueur dans write, 1 désigne la sortie standart, et str 
	désigne la chaine de caractère donnée.

2 ) juste on implémente argv[1] avec write.
	-meme mécanisme que précédemment , simplement celle ci es directement fait dans le main.

*/
