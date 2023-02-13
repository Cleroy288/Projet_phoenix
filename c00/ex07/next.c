#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		ft_putchar('0');
	}
	else if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int		main(void)
{
	ft_putnbr(990);
	ft_putchar('\n');
	ft_putnbr(4563);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(5);
	ft_putchar('\n');
	return (0);
}
/*
Ce code implémente une fonction nommée "ft_putnbr" qui affiche un nombre entier sur la sortie standard.

La fonction "ft_putchar" est utilisée pour afficher un caractère sur la sortie standard.

La fonction "ft_putnbr" utilise des conditions "if" pour déterminer comment afficher le nombre. Si le nombre est égal à 
zéro, le caractère "0" est affiché. Si le nombre est égal à -2147483648, les caractères "-" et "2" sont affichés et la 
fonction "ft_putnbr" est appelée de nouveau avec la valeur 147483648. Si le nombre est négatif, un signe moins est affiché, 
la valeur absolue du nombre est calculée, et la fonction "ft_putnbr" est appelée de nouveau avec la nouvelle valeur. Si le 
nombre est supérieur à 9, la fonction "ft_putnbr" est appelée récursivement avec les valeurs de nb/10 et nb%10 pour afficher
chacun des chiffres. Sinon, le caractère correspondant au nombre est affiché en ajoutant 48 (car les caractères numériques 
ont une valeur ASCII supérieure à 48).

Dans la fonction main, des appels à la fonction "ft_putnbr" sont effectués avec différents nombres entiers, suivis d'un 
retour à la ligne.

Le résultat de l'exécution du programme affichera les nombres entiers sur plusieurs lignes.
*/
