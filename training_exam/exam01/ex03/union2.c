#include <unistd.h>

//cherche si un char est bien dans l'autre string
int	is_char_in_other(char *s, char c)
{
	int	i = 0;
	int	j = 0;

	while (s[i])
	{
		if (c == s[i])
			j++;
		i++;
	}
	return (j);
}

//cherche si il n'est pas déja en double dans la string actuelle
int	is_char_in_dubbel(char *s, char c, int pos)
{
	int	i = 0;

	while (i < pos)
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

// vas utiliser les fonctions ci-dessus pour voir si le char peut etre affiché
void	ft_union(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;

	while (s1[i])
	{
		if (/*is_char_in_other(s1, s1[i]) > 0 &&*/ is_char_in_dubbel(s1, s1[i], i) == 0)
			write (1, &s1[i], 1);
		/*else if (is_char_in_other(s2, s1[i]) > 0 && is_char_in_dubbel(s1, s1[i], i) == 0)
			write (1, &s1[i], 1);*/
		i++;
	}
	while (s2[j])
	{
		/*if (is_char_in_other(s2, s2[j]) > 0 && is_char_in_dubbel(s2, s2[j], j) == 0)
			write (1, &s2[j], 1);
		else*/ if (is_char_in_other(s1, s2[j]) == 0 && is_char_in_dubbel(s2, s2[j], j) == 0)
			write (1, &s2[j], 1);
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write (1, "\n", 1);
}

/*

////A quoi servent les fonctions ? 
- is_char_in_other => cherche a voir si un caractère en particulier se trouve dans uen chaine de cartère donnée
- is_char_in_dubbel => cherche dans une chaine de caractère si le cartère donné en parametre a déjà été 
présentée, la boucle ne vas pas plus loin que l'emplacement même du cartère. Sela permet d'éviter
toute confusion.

///Comment fonctionne le code ?

Dans un premier temps ; 

- on traite la prmeière chaine de caractère, 
	pas besoin de vérifier que le caratère soit ailleur car en tombant dessus il est déjà 
	quoi qu'il arrive chez nous, il ne nous reste qu'a vérifier si il n'est pas en double
	et a l'afficher (vu que l'on ne traite pas la ligne pr les doublons en entier, un cartère qu'on
	a déjà croisé est un cartère qui est déjà affiché).

-On traite la seconde chiane de caratère,
	on passe la ofnction is_char_in_other a fin de vérifier si elle est présente dans la première string,
	, si la fonction renvoi 0 se qui veux dire que le caratère n'est pas présent, il peut etre affiché à 
	la condition qu'il ne soit pas en double dans notre string(il serrai alors déjà affiché et cela
	causerai une erreur de doublon).

///en conclusion ; 

(Si vous avez la flemme de lire les explications ci-dessus.)

Sachez que le code affiche les cartères non doublé de la première chaine. Puis passe a la seconde,
vérifie que le cartère sur le quel elle est n'est pas préset dans la précédente (sinonil serai déjà affiché)
et si il n'est pas en double dans la la chaine actuelle (car sinon serrai déjà affiché aussi).

 
PS : priez pour en pas tomber sur cet exo a un examen.

*/
