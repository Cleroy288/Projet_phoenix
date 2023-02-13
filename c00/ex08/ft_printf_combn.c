#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putout(int nb, int *tab, int pos)
{
	int i;

	if (pos == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	i = 0;
	while (i < nb)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	ft_print_combn_increment(int nb, int *tab)
{
	int i;
	int max;

	i = nb - 1;
	max = 9;
	while (tab[i] == max)
	{
		i -= 1;
		max -= 1;
	}
	tab[i] += 1;
	while (i < nb)
	{
		tab[i + 1] = tab[i] + 1;
		i += 1;
	}
}

void	ft_print_combn(int nb)
{
	int tab[10];
	int i;

	i = 0;
	while (i < nb)
	{
		tab[i] = i;
		i++;
	}
	ft_putout(nb, tab, 0);
	while (tab[0] != 10 - nb || tab[nb - 1] != 9)
	{
		if (tab[nb - 1] != 9)
		{
			tab[nb - 1] += 1;
		}
		else
		{
			ft_print_combn_increment(nb, tab);
		}
		ft_putout(nb, tab, 1);
	}
}
int main(int argc, const char *argv[])
{
	int len;

	len = 2;

	ft_print_combn(len);
	return 0;
}

/*
Ce programme est écrit en C et imprime toutes les combinaisons possibles de chiffres de 0 à 9 pour une longueur donnée.

Il inclut deux fonctions principales : ft_putchar() et ft_print_combn(). La première fonction, ft_putchar(), prend un 
caractère en entrée et l'imprime à l'écran en utilisant la fonction write() de la bibliothèque unistd.h. La seconde 
fonction, ft_print_combn(), prend un nombre entier en entrée qui représente la longueur de la combinaison de chiffres 
souhaitée.

La fonction ft_print_combn() définit un tableau d'entiers appelé "tab", initialise ses valeurs à 0, 1, 2, ..., nb - 1 (où 
nb est la longueur souhaitée) et appelle la fonction ft_putout() pour les imprimer. La fonction ft_print_combn_increment() 
est ensuite appelée pour incrémenter les valeurs dans le tableau "tab". Ce processus est répété jusqu'à ce que les valeurs 
dans "tab" aient atteint leur maximum possible (9 pour le dernier élément dans "tab" si nb est égal à 2, 8 pour 
l'avant-dernier élément, etc.).

En fin de compte, le programme imprimera toutes les combinaisons possibles de chiffres pour la longueur spécifiée, séparées 
par des virgules et des espaces.
*/
