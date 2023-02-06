#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

#endif
/*
Ce code définit un fichier d'en-tête (".h") en C. Il crée une structure appelée "t_point" avec 
deux variables membres, "x" et "y", qui sont des entiers. La structure est définie en utilisant 
la syntaxe "typedef struct".

Les lignes 1 à 2 sont un contrôle d'en-tête pour vérifier si ce fichier a déjà été inclus dans le 
programme. Si ce n'est pas le cas, le fichier sera inclus avec les informations de la structure "t_point".

La macro #define "FT_POINT_H" est utilisée pour définir un identificateur unique pour ce 
fichier d'en-tête. Cela permet de s'assurer que le fichier ne sera inclus qu'une seule fois.
*/
