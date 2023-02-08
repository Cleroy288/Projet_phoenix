#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void(*applyf)(void *))
{
	if (root == 0)
		return ;
	(*applyf)(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

#include <stdlib.h>
#include <stdio.h>

void	print_item(void *item)
{
	int	*nbr = (int *)item;
	printf("%d\n", *nbr);
}

int	main()
{
	t_btree *root = malloc(sizeof(t_btree));
    	int *nbr1 = malloc(sizeof(int));
    	*nbr1 = 1;
    	int *nbr2 = malloc(sizeof(int));
    	*nbr2 = 2;
    	int *nbr3 = malloc(sizeof(int));
    	*nbr3 = 3;
    	int *nbr4 = malloc(sizeof(int));
    	*nbr4 = 4;
    
	root->item = nbr1;
    	root->left = malloc(sizeof(t_btree));
    	root->left->item = nbr2;
    	root->left->left = NULL;
    	root->left->right = NULL;
    	root->right = malloc(sizeof(t_btree));
    	root->right->item = nbr3;
    	root->right->left = malloc(sizeof(t_btree));
    	root->right->left->item = nbr4;
    	root->right->left->left = NULL;
    	root->right->left->right = NULL;
    	root->right->right = NULL;
    	btree_apply_prefix(root, print_item);
    	return (0);
}

/*

Ce code est une fonction nommée "btree_apply_prefix" qui parcourt un arbre 
binaire en utilisant l'algorithme de parcours prefixe. 
Cela signifie que la fonction "applyf" donnée en paramètre sera appliquée à 
chaque noeud de l'arbre dans l'ordre suivant:

Le noeud racine (root)
Le sous-arbre gauche
Le sous-arbre droit

La fonction "applyf" peut être n'importe quelle fonction que vous souhaitez exécuter 
pour chaque noeud de l'arbre. Elle prend en entrée un "void *" qui représente 
l'item stocké dans ce noeud en particulier.

L'algorithme de parcours prefixe est implémenté à l'aide de la récursion. 
La fonction s'appelle elle-même pour chaque sous-arbre gauche et droit de la 
racine jusqu'à ce qu'elle ait parcouru tous les noeuds de l'arbre.

Lorsqu'elle est utilisée avec un arbre binaire, cette fonction permet de parcourir 
tous les noeuds de l'arbre dans un ordre précis, ce qui peut être utile pour 
diverses tâches telles que la modification de tous les noeuds, l'affichage de 
tous les éléments, etc.

*/
