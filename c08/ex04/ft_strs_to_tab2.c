#include "ft_stock_str.h"
#include <stdlib.h>


/*struct	s_stock_str	*ft_strs_to_tab(int ac, char *avv)
{

}*/

#include <stdio.h>

/*
typedef struct s_stock_str
{
    int     size;
    char    *str;
    char    *copy;
}                       t_stock_str;
*/
int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
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

int main(int argc, char *argv[])
{
	t_stock_str *result = ft_strs_to_tab(argc - 1, argv + 1);
	int	i = 0;

	while (result[i].str != NULL)
	{
		printf("Size: %d\n", result[i].size);
		printf("Str: %s\n", result[i].str);
		printf("Copy: %s\n", result[i].copy);
		i++;
	}
	return 0;
}

/*
"s_stock_str" et "t_stock_str" sont deux noms différents pour définir la même structure. 
Les noms de structure peuvent être choisis librement et il est courant d'utiliser un préfixe "s_" pour 
les structures et un préfixe "t_" pour les types de structure. En fin de compte, la seule chose qui 
importe est que les noms soient uniques et que vous les utilisiez de manière cohérente dans votre code.

/////////// COMMENT FONCTIONNE LE CODE ?

La fonction ft_strlen calcule la longueur de la chaîne de caractères passée en argument et renvoie 
le nombre de caractères. Elle utilise une boucle pour parcourir la chaîne de caractères jusqu'à ce 
qu'elle rencontre un caractère nul ('\0'). La longueur est retournée en tant que valeur entière.

La fonction ft_strdup crée une copie dynamique d'une chaîne de caractères passée en argument. 
Elle utilise la fonction ft_strlen pour déterminer la longueur de la chaîne de caractères source 
et alloue suffisamment d'espace mémoire pour la copie. Elle utilise ensuite une boucle pour copier 
les caractères de la source vers la copie et ajouter un caractère nul à la fin. Le pointeur vers 
la copie est renvoyé en tant que valeur de retour.

La fonction ft_strs_to_tab crée un tableau de structures t_stock_str qui contient des informations 
sur les chaînes de caractères passées en argument. Elle utilise la fonction malloc pour allouer 
suffisamment d'espace mémoire pour le nombre de chaînes de caractères passées en argument, 
ajoutant un élément supplémentaire pour la terminaison du tableau. Elle utilise ensuite une boucle pour 
remplir les champs de chaque structure avec la longueur de la chaîne de caractères obtenue à l'aide 
de ft_strlen, la chaîne de caractères elle-même obtenue à l'aide de ft_strdup et une copie de la 
chaîne de caractères obtenue également à l'aide de ft_strdup. Enfin, elle définit le champ str de la 
dernière structure pour être NULL, ce qui indique la fin du tableau.

Le main utilise la fonction ft_strs_to_tab pour obtenir un tableau de structures t_stock_str qui 
contient des informations sur les chaînes de caractères passées en argument au programme. 
Il utilise ensuite une boucle pour afficher les informations sur chaque structure jusqu'à ce qu'il 
atteigne une structure où le champ str est NULL, indiquant la fin du tableau.

*/

