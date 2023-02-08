#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void(*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}
/*

L'exercice consiste à écrire une fonction "btree_apply_infix" qui prend en entrée un pointeur sur un noeud 
d'un arbre binaire "root" et un pointeur sur une fonction "applyf" qui sera appliquée à l'item de chaque 
noeud de l'arbre. La fonction parcourt l'arbre de manière infix, c'est-à-dire en visitant tout d'abord le 
sous-arbre gauche, puis la racine, et enfin le sous-arbre droit.

Le code utilise la récursion pour parcourir l'arbre de manière infix. Si la racine de l'arbre est nulle, la 
fonction se termine immédiatement. Sinon, elle appelle la fonction btree_apply_infix sur le sous-arbre gauche, 
puis elle appelle la fonction "applyf" sur l'item de la racine et enfin elle appelle btree_apply_infix sur le 
sous-arbre droit.

*/
