/*

Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$

*/

#include <unistd.h>

int	is_in_str(char *str, char c, int pos)
{
	static int	i = 0;
	while (str[i])
	{
		if (str[i] == c && i > pos)
			return (1);
		i++;
	}
	return (0);
}

void	wdmatch(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	int	len = 0;

	while (s1[i])
	{
		if (is_in_str(s2, s1[i], i) == 1)
			len++;
		i++;
	}
	while (s1[j])
		j++;
	if (j == len)
		write (1, s1, j);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		wdmatch(argv[1], argv[2]);
	}
	write (1, "\n", 1);
}

/*

Se code utilise un fonction externe, appellé is_in_str, elle  prend un cartère et vas
voir si celui-ci se trouve dans la string de "comparaison". Le point important est le static int, 
qu'est ce que c'est que un static int ? => un dont la valeur ne retourne pas a zero a chaque fois que la fonction
est appelée.

Mais pour quoi avoir fait cela ? => L'énoncé dit que le cartère doit suivre l'ordre dans le quel les cartères
sont disposés dans le string de comparaison. En dautre termes une ofis avoir avancé vous ne pouvez pas 
retourner en arrière. 
C'est exactement ce que permet de faire le static int il ne fait que avancer et ne recule jamais
(sauf si on le lui demande).

Soit. Dans la condition de cette fonction (ligne 39) on dit que si un cartère est trouvé, celui-ci doit etre 
positionnée a une valeur plus haute que pos. (ce qui est logique, car l'on doit suivre l'ordre dans le quel 
ses cartères apparaissent dans la string de comparaison, en d'autre termers on ne peut utiliser que des char 
qui sont donc a une positions supérieur a la notre).

Si cette conditon est rempli un (1) est renvoyé.

Cette fonction est alors utilisé dans la fonctin principale wdmatch. Si cette fonction renvoi 1, len est
incrémenté.

Après etre sorti de la boucle, une seconde boucle destiné a trouver la longueur de s1 commence, celle-ci 
incrémente j jusqu'a ne plus etre valide (cette boucle ne sert a rien vous pouvez vous en passer, la boucle 
précédente fait extactement la meme chose avec i)

la condition de fin vérifie si len == j , si c'est le cas la string est affiché, si ce n'est pas le cas c'est que
un cartère n'était pas bon (ne rentrait pas dans les conditions de is_in_str) et du ccoup la
 string (mot a afficher) n'est pas affiché / écrit.
 
*/
