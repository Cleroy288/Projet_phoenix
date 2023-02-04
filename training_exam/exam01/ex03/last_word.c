/*

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/

#include <unistd.h>

int	is_char(char c)
{
	if ((c >= 'a' && c <= 'z') || (c <= 'A' && c >= 'Z'))
		return (1);
	return (0);
}

void	last_word(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	while (is_char(str[i]) == 0)
		i--;
	while (is_char(str[i]) == 1)
		i--;
	if (is_char(str[i]) == 0)
		i++;
	while (is_char(str[i]) == 1)
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		last_word(argv[1]);
	}

}

/*

Le code ci-dessus est un programme en C qui imprime la dernière mot d'une chaîne de caractères passée en argument. Il comprend plusieurs fonctions et instructions qui travaillent ensemble pour atteindre ce but.

La fonction is_char(char c) vérifie si un caractère est une lettre majuscule ou minuscule. Elle renvoie 1 si c'est le cas, 0 sinon.

La fonction last_word(char *str) trouve le dernière mot dans la chaîne de caractères str. 
Elle utilise une boucle while pour parcourir les caractères de la chaîne, à partir de la fin, jusqu'à trouver 
le premier caractère qui est une lettre. Elle utilise alors la fonction is_char pour vérifier si les 
caractères sont des lettres et continue à reculer jusqu'à ce qu'elle rencontre un caractère qui n'est pas 
une lettre. Le code saute ensuite à la première lettre du  dernière mot et utilise une autre boucle while 
pour imprimer les caractères restants du  dernière mot.

La fonction principale int main(int argc, char **argv) vérifie si le nombre d'arguments est égal à 2. 
Si c'est le cas, la fonction last_word est appelée avec le premier argument. Sinon, le programme ne fait rien.

En résumé, le code trouve la dernière mot d'une chaîne de caractères en utilisant des boucles while et des
appels de fonction pour parcourir la chaîne de caractères à partir de la fin et imprimer la dernière mot.

*/
