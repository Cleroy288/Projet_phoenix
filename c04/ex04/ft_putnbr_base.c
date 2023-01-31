#include <unistd.h>
//les explications et le principe de se code se trouvent plus bas.
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_check_base(char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_l;
	char	nbr_c[32];
	int		base_divider;
	int		i;

	if (!ft_check_base(base))
		return ;
	base_divider = ft_strlen(base);
	if (nbr < 0)
	{
		nbr_l = nbr;
		nbr_l = -nbr_l;
		ft_putchar('-');
	}
	else
		nbr_l = nbr;
	i = 0;
	while (nbr_l > 0)
	{
		nbr_c[i] = base[nbr_l % base_divider];
		nbr_l /= base_divider;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbr_c[i]);
}

int     main(void)
{
    char base[]="01";
    ft_putnbr_base(8,base);
    return (0);
}
/*

/////////////////// COMMENT FONCTIONNE LE CODE ?
Ce code implémente une fonction ft_putnbr_base qui prend en entrée un nombre entier et une base sous forme de chaîne de caractères et affiche le nombre entier en base donnée. Le code implémente également une fonction ft_check_base qui vérifie si la base est valide.

La fonction ft_check_base s'assure que la base est valide en vérifiant que :

La longueur de la base est d'au moins 2 caractères.
La base ne contient pas de signes (+/-), de caractères de contrôle, ni de caractères qui ne sont pas imprimables (c'est-à-dire inférieurs à 32 ou supérieurs à 126).
La base ne contient pas deux caractères identiques.
Si la base est considérée comme valide, la fonction ft_putnbr_base convertit le nombre entier en base donnée en utilisant la méthode de division modulo. Le nombre entier est d'abord converti en un nombre long pour permettre une conversion correcte même si le nombre entier est négatif. Chaque division par la base diviseur donne le prochain chiffre de la conversion, qui est stocké dans un tableau de caractères. Finalement, ce tableau est parcouru à l'envers et les caractères sont affichés en utilisant la fonction ft_putchar qui affiche simplement un caractère à l'écran.

Le code comprend également une fonction ft_strlen qui calcule la longueur d'une chaîne de caractères et une fonction ft_putchar qui affiche un caractère à l'écran.

Enfin, le programme principal appelle la fonction ft_putnbr_base avec le nombre 8 en entrée et la base "01", ce qui affichera le nombre 8 en binaire.

EXPLIQUEE AUTREMENT ;

Ce code permet de convertir un nombre entier en une autre base numérique. La conversion se fait grâce à la fonction ft_putnbr_base qui prend en entrée un nombre (nbr) et la base dans laquelle on souhaite le convertir (base).

Avant de commencer la conversion, le code vérifie si la base entrée est valide à l'aide de la fonction ft_check_base. Pour être considérée comme valide, la base doit comporter au moins deux chiffres et ne peut contenir ni le signe plus ni moins, ni des caractères non-imprimables.

Si la base est valide, la conversion commence. Le nombre est alors divisé par la longueur de la base (base_divider) pour trouver le chiffre à sa place. Ce processus est répété jusqu'à ce que le nombre soit inférieur à zéro. Chaque chiffre obtenu est stocké dans un tableau nbr_c.

Enfin, les chiffres stockés dans nbr_c sont affichés dans l'ordre inverse à l'aide de la fonction ft_putchar. Cela permet d'afficher le nombre converti dans la nouvelle base.

Dans l'exemple du main, le nombre 42 en base 10 est converti en base binaire (représenté par "01"). Le résultat affiché sera "101010".

////////////////////////POUR QUOI NBR_C EST DE TAILLE 32 ?

nbr_c est un tableau de caractères qui stocke la représentation binaire (ou dans une autre base) d'un nombre entier. La taille 32 est probablement choisie pour garantir que la représentation binaire de n'importe quel nombre entier peut être stockée dans le tableau, même si ce n'est pas toujours nécessaire. Cela dépend de la base choisie et de la plage de nombres que l'on souhaite convertir.


/////////////// COMMENT SE PASSE LA CONVERSION ? 

La conversion de l'entier en base spécifiée se fait en suivant ces étapes :

Déterminer la longueur de la base de conversion, en utilisant la fonction ft_strlen(base).
Déterminer si la base est valide en utilisant la fonction ft_check_base(base). Si la base n'est pas valide, la fonction renvoie 0 et la fonction ft_putnbr_base se termine.
Convertir l'entier en base n (où n est la longueur de la base) en utilisant le modulo et la division. Chaque étape de la boucle while (nbr_l > 0) divise nbr_l par base_divider et stocke le reste dans le tableau nbr_c à la position i.
Imprimer les valeurs stockées dans nbr_c en utilisant la fonction ft_putchar dans la boucle while (--i >= 0). Les valeurs sont imprimées dans l'ordre inverse de celui dans lequel elles ont été stockées dans nbr_c, ce qui garantit que le nombre soit affiché dans le bon ordre.

donc ; 

Le code convertit un nombre donné en une autre base numérique. Le nombre d'origine est représenté en base décimale (base 10) et est converti en une autre base numérique, telle que la base binaire (base 2) ou hexadécimale (base 16).

Prenons l'exemple de 42 en base 10. Si nous voulons le convertir en base binaire, nous effectuons les étapes suivantes :

Divisez 42 par 2 pour trouver le quotient et le reste.
Le premier reste est 0, le quotient est 21.
Divisez 21 par 2 pour trouver le quotient et le reste.
Le premier reste est 1, le quotient est 10.
Divisez 10 par 2 pour trouver le quotient et le reste.
Le reste est 0, le quotient est 5.
Divisez 5 par 2 pour trouver le quotient et le reste.
Le reste est 1, le quotient est 2.
Divisez 2 par 2 pour trouver le quotient et le reste.
Le reste est 0, le quotient est 1.
Divisez 1 par 2 pour trouver le quotient et le reste.
Le reste est 1, le quotient est 0.
Le nombre 42 en base 10 est donc converti en 101010 en base binaire.

Le code implémente cette conversion en utilisant la division et le modulo. À chaque itération, le nombre est divisé par la base de destination et le reste est ajouté à une chaîne de caractères. Finalement, cette chaîne de caractères est affichée à l'envers pour donner le résultat final.

////////// C'EST QUOI UNE BASE PAS VALIDE ?

Une base non valide est une base qui ne respecte pas les critères suivants :

Elle doit contenir au moins 2 caractères différents.
Aucun des caractères de la base ne doit être un signe de plus ou de moins, ni être inférieur à 32 (espace) ou supérieur à 126 (~).
Les caractères de la base ne doivent pas se répéter.

///////// C'EST QUOI UNE BASE ?

Une base est un nombre utilisé pour représenter les nombres dans une numération différente de la base 10 (décimale). Il existe plusieurs bases couramment utilisées, telles que la base 2 (binaire), la base 8 (octale) et la base 16 (hexadécimale). La base détermine le nombre de chiffres différents utilisés pour représenter les nombres et, par conséquent, la quantité de données qui peuvent être stockées pour chaque chiffre.

//////// QUEL BASE A ETE UTILISEE ET COMMENT AFFICHER LES AUTRES

la base utilisée dans l'exemple est la base binaire, représentée par "01". Pour représenter d'autres bases, on peut utiliser n'importe quel séquence de caractères, à condition que la longueur soit supérieure à 1 et que chaque caractère soit unique. Par exemple, la base décimale peut être représentée par "0123456789", la base hexadécimale par "0123456789ABCDEF", etc.


//////// MON CERVEAU CHAUFFE DONNE UN EXMPLE SIMPLE 

Le code convertit un nombre en une autre base en utilisant un système de numération différent. Pour ce faire, le nombre est divisé par la base choisie, et le reste de la division est utilisé pour représenter le chiffre de la nouvelle base. Ce processus est répété jusqu'à ce que le quotient soit 0. Les restes sont ensuite écrits dans l'ordre inverse pour donner la valeur finale dans la nouvelle base. Par exemple, pour convertir le nombre 10 en base 2 (binaire), le nombre est divisé par 2 jusqu'à ce que le quotient soit 0. Les restes sont alors écrits dans l'ordre inverse: 1010 (binaire) = 10 (décimal).

///////////POUR QUOI LE RESULTAT EST AFFICHEE A L'ENVERS ?

Le résultat est affiché à l'envers parce que la conversion se fait en partant des unités (ou des bits les plus à droite) pour arriver aux puissances de 10 (ou de la base) les plus élevées. Le code stocke d'abord le résultat de la conversion dans un tableau nbr_c, en partant des unités. Puis, pour l'affichage, le code parcourt ce tableau à l'envers, en commençant par la dernière position et en finissant à la première. C'est pourquoi le résultat final est affiché à l'envers.

Le code convertit un nombre en une autre base. Pour ce faire, il divise le nombre par la base choisie (par exemple la base binaire "01") jusqu'à ce que le résultat soit 0. À chaque division, le reste est stocké dans un tableau nommé "nbr_c". Une fois les divisions terminées, le tableau "nbr_c" contient les chiffres de la conversion. Enfin, pour afficher le résultat, le code parcourt le tableau "nbr_c" de la fin vers le début et affiche chaque chiffre. C'est pour cela que le résultat est affiché à l'envers.

////// POUR QUOI CA FONCTIONNE DIVISER UN CHIFRRE PAR 2 POUR L'OBTENIR EN BINAIRE ?

Le système binaire utilise seulement 2 chiffres, 0 et 1. Pour convertir un nombre en binaire, nous divisons répétitivement ce nombre par 2 et enregistrons le reste à chaque étape. Le dernier reste obtenu indique le premier chiffre du nombre en binaire. Les autres restes obtenus lors des divisions successives sont ensuite lus à l'envers pour obtenir le nombre binaire complet. Cela fonctionne car le système de numération binaire ne peut représenter que des puissances de 2, ce qui est exactement ce que nous obtenons en divisant un nombre par 2 et en enregistrant les restes.
*/
