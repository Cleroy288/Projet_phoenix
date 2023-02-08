#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmp)(void *, void *))
{
	if (!root)
		return (NULL);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (cmpf(data_ref, root->item) < 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	return (btree_search_item(root->right, data_ref, cmf));
}

/*
Pour faire cet exercice, nous allons écrire une fonction appelée btree_search_item. 
Cette fonction prend en entrée un arbre binaire (t_btree *root), une donnée de référence (void *data_ref), 
et une fonction de comparaison (int (*cmpf)(void *, void *)). La fonction de comparaison aura le même 
comportement que strcmp.

Le but de la fonction btree_search_item est de parcourir l'arbre de manière infix et de retourner le premier 
élément qui correspond à la donnée de référence passée en paramètre. Si l'élément n'est pas trouvé, 
la fonction retourne NULL.

Pour implémenter cette fonction, nous allons utiliser une approche récursive. Nous commencerons par vérifier 
si la racine de l'arbre est nulle. Si c'est le cas, nous retournerons NULL, car l'élément recherché n'a pas 
été trouvé. Si la racine n'est pas nulle, nous utiliserons la fonction de comparaison pour déterminer si 
la donnée de référence est plus petite, égale ou plus grande que l'élément actuel.

Si la donnée de référence est plus petite que l'élément actuel, nous appellerons récursivement 
btree_search_item sur le sous-arbre gauche de l'arbre. Si la donnée de référence est plus grande ou égale 
à l'élément actuel, nous appellerons récursivement btree_search_item sur le sous-arbre droit de l'arbre.

Nous continuerons à appeler récursivement btree_search_item jusqu'à ce que nous trouvions l'élément 
correspondant ou que nous arrivions à une feuille de l'arbre où l'élément n'a pas été trouvé. Dans ce cas, 
nous retournerons NULL.


concretement ca se passe comment ? 

On appelle la fonction cmpf avec les données de référence data_ref et l'item actuel de l'arbre root->item. 
La fonction retourne 0 si les items sont égaux, un nombre négatif si l'item de référence est plus petit 
que l'item actuel, et un nombre positif si l'item de référence est plus grand que l'item actuel. 
On enregistre le résultat dans cmp_result

La ligne 9 est une instruction de comparaison qui utilise la fonction de comparaison passée en paramètre 
cmpf pour comparer data_ref et root->item. Si la valeur retournée par cmpf est inférieure à zéro, 
cela signifie que data_ref est inférieur à root->item et que nous devons continuer à parcourir la 
partie gauche de l'arbre pour trouver notre élément.
*/
