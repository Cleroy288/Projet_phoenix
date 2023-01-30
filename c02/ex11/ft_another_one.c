#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_printable(str[i]) == 1)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str[i] / 16]);
			ft_putchar("0123456789abcdef"[str[i] % 16]);
		}
		i++;
	}
}

int main (void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien");
	ft_putchar('\n');
	ft_putstr_non_printable("Coucou tu vas bie\t\v\0n");
	ft_putchar('\n');
	ft_putstr_non_printable("");
	ft_putstr_non_printable("les aveugles tutoient car\n ils ne vous-voient-pas");
	ft_putchar('\n');
}

/*
La table de conversion "0123456789abcdef" est utilisée pour convertir des valeurs décimales en valeurs hexadécimales.

En mathématiques hexadécimales, la base est 16 et les 10 premiers chiffres sont les mêmes que dans le système décimal (0 à 9). Pour représenter les nombres supérieurs à 9, on utilise les 6 premières lettres de l'alphabet (a à f).

Lors de la conversion en hexadécimal, la valeur décimale est divisée par 16 et le reste est utilisé pour déterminer la valeur unitaire (0 à 15) qui est convertie en son équivalent hexadécimal (0 à 9 ou a à f). Cette opération est répétée jusqu'à ce que la valeur décimale soit inférieure à 16. Les valeurs hexadécimales sont concaténées pour donner la valeur hexadécimale complète.

Dans ce code, la table de conversion est utilisée pour convertir la valeur d'un octet (une valeur décimale comprise entre 0 et 255) en sa notation hexadécimale équivalente. Les deux appels à "ft_putchar" avec l'expression "ft_putchar("0123456789abcdef"[str[i] / 16])" et "ft_putchar("0123456789abcdef"[str[i] % 16])" sont utilisés pour afficher les valeurs hexadécimales des unités et des dizaines respectivement. La valeur de l'unité est déterminée par le reste de la division par 16, et la valeur des dizaines est déterminée par la valeur entière de la division par 16.

*/ 

/*
Cette syntaxe implique l'utilisation d'un tableau de caractères (ou chaîne de caractères) pour accéder à un élément spécifique en utilisant une expression entre crochets.

La chaîne de caractères "0123456789abcdef" représente la table de conversion décrite dans ma réponse précédente, utilisée pour convertir des valeurs décimales en valeurs hexadécimales.

L'expression "str[i] / 16" représente le résultat de la division de la valeur décimale de l'octet à la position "i" dans la chaîne "str" par 16. Cette expression détermine la valeur hexadécimale des dizaines.

Lorsque cette expression est utilisée entre crochets après la chaîne de caractères, elle accède à l'élément de la table de conversion correspondant à la valeur hexadécimale des dizaines. Par exemple, si le résultat de "str[i] / 16" est 3, l'expression accédera au quatrième caractère de la chaîne, qui est "3".

L'appel à "ft_putchar" avec cette expression en argument affichera donc le caractère correspondant à la valeur hexadécimale des dizaines sur la sortie standard. La même opération est effectuée pour la valeur hexadécimale des unités avec l'expression "str[i] % 16".
*/
