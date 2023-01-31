
int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

#include<stdio.h>
int	main(void)
{
	int	nb;

	nb = 12;
	printf("%d\n", ft_recursive_factorial(nb));
	return(0);
}

/*
///////////C'EST QUOI LA RECURSIVITE ?

La récursivité en C est une technique de programmation consistant à définir une fonction qui s'appelle elle-même. Cela permet de résoudre des problèmes en les divisant en sous-problèmes de taille plus petite et en utilisant la fonction elle-même pour les résoudre. La récursivité est utilisée pour des algorithmes qui se répètent jusqu'à ce qu'une condition soit remplie. Il est important de définir une condition d'arrêt pour éviter une récursion infinie.

/////// COMMENT FONCTIONNE SE CODE ? 

Ce code calcule la factorielle d'un nombre entier nb à l'aide de la récursivité. La fonction "ft_recursive_factorial" est appelée récursivement jusqu'à ce que nb soit égal à 0 ou 1. Dans ce cas, la fonction renvoie 1. Sinon, la fonction renvoie nb multiplié par l'appel récursif de la fonction avec nb-1. Le résultat final est donc la factorielle de nb.
*/
