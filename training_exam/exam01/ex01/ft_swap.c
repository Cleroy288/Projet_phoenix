/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>
int main()
{
	int	a, b;
	a = 1;
	b = 2;

	ft_swap(&a, &b);
	printf("A doit etre devenu 2 => %d\n", a);
	printf("B doit etre devenu 1 => %d\n", b);
}

/*
Les étapes a suivre et la logique en 3 étapes

1 ) - Le int tmp Prend la valeur contenu dans le pointeur *a,
2 ) - Le pointeur (*a) prend la valeur du pointeur (*b).
3 ) - Le pointeur (*b) prend la valuer de tmp, ayant la valeur contenu dans le pointeur (*a).

POUR QUOI on ne fait pas CA ??
*a = *b;
*b = *a; 

Car ;

Si *a contient (1), et *b continet (2)
et que l'on fait;
*a = *b; // donc => b = (1);
*b = *a; // donc => b étant devenu 1 du au premier swap, il rend ca valeur 1 au pointeur *a;

En gros les 2 obtinederons la valeur 1;
d'ou le besoin de stocker la prmeier valeur dans une variable (tmp) dans notre cas dit "temporaire";

*/
