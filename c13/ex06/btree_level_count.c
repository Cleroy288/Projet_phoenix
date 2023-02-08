#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	if (root == NULL)
		return (0);
	int	left_depth = btree_level_count(root->left);
	int	right_depth = btree_level_count(root->right);
	if (left_depth > right_depth)
		return (left_depth + 1);
	else
		return (right_depth + 1);
	// OU // return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

/*
Pour résoudre cet exercice, nous pouvons utiliser une approche basée sur la profondeur de l'arbre binaire. 
Nous commencerons par trouver la profondeur de la branche gauche et de la branche droite, puis nous 
retournerons la plus grande de ces deux valeurs, ajoutée de 1 pour inclure la racine elle-même.

Dans cette implémentation, nous utilisons une récursion pour descendre dans l'arbre et trouver la profondeur 
de chaque branche. Nous comparons la profondeur de la branche gauche et de la branche droite, et retournons 
la plus grande de ces deux valeurs plus 1 pour inclure la racine. Si la racine est NULL, nous 
retournons simplement 0.
*/
