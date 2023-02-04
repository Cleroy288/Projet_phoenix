/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

int	check_dub(char *str, char c, int pos)
{
	int	i = 0;

	while (i < pos)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}


void	inter(char *str1, char *str2)
{
	int	i = 0;
	int	j;

	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j] && check_dub(str1, str1[i], i) == 0)
			{
				write (1, &str1[i], 1);
				break;
			}
		j++;
		}
	i++;
	}
}



int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
	}

}

/*
/////COMMENT CA FONCTIONNE ? 

Le code implémente une fonction "inter" qui prend en entrée deux chaînes de caractères (str1 et str2) 
et affiche les caractères qui sont présents dans les deux chaînes.

La fonction "inter" utilise une boucle "while" (ligne 48 à 61) pour parcourir les 
caractères de la première chaîne de caractères (str1). Pour chaque caractère de str1, 
une autre boucle "while" (ligne 51 à 59) est utilisée pour parcourir les caractères de 
la seconde chaîne de caractères (str2). Si un caractère trouvé dans str1 est également 
présent dans str2 et n'a pas encore été affiché (vérifié en utilisant la fonction "check_dub"), 
ce caractère est affiché à l'aide de la fonction write (ligne 55) et la boucle intérieure est 
interrompue en utilisant "break" (ligne 56).

La fonction "check_dub" (ligne 30 à 40) est utilisée pour vérifier si un caractère a déjà été affiché en 
parcourant les caractères précédents de str1 jusqu'à la position actuelle (pos). 
Si un caractère égal à c est trouvé, la fonction retourne 1, sinon elle retourne 0.

Le main (ligne 66 à 73) vérifie que le nombre d'arguments passés en entrée est égal à 3 
(les deux chaînes de caractères et le nom du programme), puis appelle la fonction "inter" en 
passant les deux chaînes de caractères en entrée.


///////////BREAK ??

Dans ce code, le mot clé "break" est utilisé dans la fonction "inter" pour sortir de la boucle intérieure 
(ligne 51 à 59) lorsqu'un caractère est trouvé dans les deux chaînes de caractères (str1 et str2). 
Si un caractère est trouvé dans les deux chaînes de caractères et que ce caractère n'a pas encore été 
affiché (vérifié en utilisant la fonction "check_dub"), il est affiché à l'aide de la fonction write 
(ligne 55) et la boucle intérieure est interrompue en utilisant "break" (ligne 56). 
Cela permet de ne pas afficher plusieurs fois le même caractère.

*/
