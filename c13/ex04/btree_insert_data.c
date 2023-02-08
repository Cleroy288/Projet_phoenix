
#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmp)(void *, void *))
{
	t_btree	*node;

	if (!*root)
	{
		node = malloc(sizeof(t_btree));
		node->left = NULL;
		node->right = NULL;
		node->item = item;
		*root = node;
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}

/*

La fonction btree_insert_data est une fonction qui permet d'insérer un élément "item" dans un arbre 
binaire. Cet arbre est considéré comme trié, ce qui signifie que pour chaque nœud, tous les éléments plus 
petits se trouvent à gauche et tous les éléments plus grands ou égaux se trouvent à droite. Cette fonction 
utilise une fonction de comparaison pour déterminer où insérer l'élément "item". Cette fonction de 
comparaison est similaire à la fonction strcmp en ce sens qu'elle compare deux valeurs.

La syntaxe &(*root) est utilisée pour accéder à l'adresse mémoire du nœud racine de l'arbre. Cela permet 
de pouvoir modifier les nœuds de l'arbre pendant l'exécution du programme.

Le code fonctionne en vérifiant si la valeur de l'élément à insérer est plus petite que la valeur de 
l'élément du nœud actuel. Si c'est le cas, la fonction btree_insert_data est appelée sur la branche gauche 
du nœud actuel. Si la valeur de l'élément à insérer est plus grande ou égale, la fonction btree_insert_data 
est appelée sur la branche droite. Ce processus est répété jusqu'à ce qu'une position vide soit trouvée 
pour l'insertion de l'élément.

Lors du premier appel à la fonction btree_insert_data, le pointeur "root" pointe sur NULL. La fonction 
allouera alors un nouveau nœud pour l'élément "item" et mettra à jour le pointeur "root" pour qu'il pointe 
sur ce nouveau nœud. Les appels ultérieurs à la fonction btree_insert_data utiliseront le nœud racine pour 
trouver la position correcte pour l'insertion de l'élément "item".

*/
