#include <stdlib.h>

//srlen classique utilisé dans la prochaine fonction.
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
compte 2 fois la base une fois avec strlen, puis en fonction de cela,
une autre fois avec des conditions adapté en fonction de la longueur recu et donc le type de base.
Une fois passé par le 2 eme processus de vérification les 2 longueurs sont comparées, si elles sont 
identiques, cela signiifie que la base est valide, si ce n'est pas le cas c'est que la base  ne l'était pas.

PS : la prmeiere condition  vérifique que jai bien une longueur correcte.cad 2, 8, 10 ou 16 elle vérifie aussi
que base ne sois pas zéro.
*/
int	give_and_test_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(base);
	if (base == NULL)
		return (-1);;
	while (base[i])
	{
		if (j == 8)
			while (base[i] >= '0' && base[i] <= '7')
				i++;
		else if (j == 10)
			while (base[i] >= '0' && base[i] <= '9')
				i++;
		else if (j == 2)
			while (base[i] == '0' || base[i] == '1')
				i++;
		else if (j == 16)
			while (base[i] >= '0' && base[i] <= '9' ||
				base[i] >= 'a' && base[i] <= 'f')
				i++;
	}
	if (i == j)
		return (i);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

#include <stdio.h>

int	main()
{
	char	str[] = "01";

	printf("%d\n", give_and_test_base(str));
	printf("%d\n", ft_strlen(str));

}
