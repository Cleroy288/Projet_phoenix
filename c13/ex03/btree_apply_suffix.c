#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void(*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_infix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}
/*

L'exercice consiste à écrire une fonction btree_apply_suffix qui prend en entrée un pointeur sur la 
racine d'un arbre binaire et une fonction applyf. La fonction btree_apply_suffix doit parcourir l'arbre 
de manière suffix (c'est-à-dire en visitant d'abord les nœuds de gauche, puis les nœuds de droite et enfin 
la racine) et pour chaque nœud, appeler la fonction applyf en lui passant en argument l'item associé au nœud.

Le code parcourt récursivement l'arbre en utilisant une approche DFS (depth-first search). D'abord, il 
visite les nœuds de gauche, puis les nœuds de droite et enfin la racine en appelant la fonction applyf 
sur l'item associé à chaque nœud.

*/
