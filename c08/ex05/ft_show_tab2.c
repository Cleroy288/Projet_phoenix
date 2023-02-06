#include <unistd.h>
#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	long	nb;
	int		i;
	char	c[10];

	nb = nbr;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	i = 0;
	while (nb > 0)
	{
		c[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(c[i]);
		i--;
	}
}
char	*ft_strdup(char *src)
{
	int	i = 0;
	int	len;
	char	*dest;

	len  = ft_strlen(src);
	dest = (char*)malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return NULL;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ptr;
	int	i;

	i = 0;
	if (!(ptr = (t_stock_str*)malloc(sizeof(*ptr) * (ac + 1))))
		return NULL;
	while (i < ac)
	{
		ptr[i].size = ft_strlen(av[i]);
		if (!(ptr[i].str = ft_strdup(av[i])))
			return NULL;
		else if (!(ptr[i].copy = ft_strdup(av[i])))
			return NULL;
		i++;
	}
	ptr[i].str = NULL;
	return ptr;
}

void    ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void    ft_show_tab(t_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putstr("Size: ");
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr("Copy: ");
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stock_str *tab = ft_strs_to_tab(argc - 1, argv + 1);
	ft_show_tab(tab);
	return 0;
}

/*
////////////COMMENT FONCTIONNE LE CODE ?

Ce code est un programme en C qui gère des chaînes de caractères (strings) et des tableaux de chaînes de caractères.

Il y a plusieurs fonctions définies dans ce code :

=> ft_strlen : Cette fonction calcule la longueur d'une chaîne de caractères en parcourant les caractères un par un jusqu'à trouver le caractère nul ('\0').
=> ft_strdup : Cette fonction crée une copie d'une chaîne de caractères en allouant de la mémoire pour un nouveau tableau de caractères de même longueur que 
la chaîne source, puis en copiant les caractères dans le nouveau tableau.
=> ft_strs_to_tab : Cette fonction crée un tableau de structures t_stock_str à partir de deux arguments : un entier ac qui représente le 
nombre de chaînes de caractères et un tableau de chaînes de caractères av. Chaque élément de la structure t_stock_str contient une chaîne de caractères (str), 
une copie de la chaîne (copy), et la longueur de la chaîne (size).
=> ft_putstr : Cette fonction affiche une chaîne de caractères sur la sortie standard (écran).
=> ft_show_tab : Cette fonction affiche tous les éléments du tableau de structures t_stock_str.
=> Enfin, la fonction main utilise ces fonctions pour créer un tableau de structures t_stock_str à partir des arguments passés au programme, puis 
affiche le contenu de ce tableau en utilisant la fonction ft_show_tab.

//////////COMMENT FONCTIONNE FT_SHOW_TAB ?

La fonction ft_show_tab affiche les informations contenues dans un tableau de structure t_stock_str. Pour chaque élément du tableau, elle 
utilise la fonction ft_putstr pour afficher la chaîne de caractères stockée dans par[i].str, 
suivie d'un retour à la ligne. Ensuite, elle affiche "Size: " et utilise ft_putnbr pour afficher la 
taille de la chaîne de caractères stockée dans par[i].size, suivie d'un retour à la ligne. Elle répète ce processus pour afficher la chaîne 
de caractères stockée dans par[i].copy. La boucle continue jusqu'à ce que le champ par[i].str soit égal à NULL, indiquant la fin du tableau.

*/
