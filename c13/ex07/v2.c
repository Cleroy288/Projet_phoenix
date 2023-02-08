#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree
{
	struct s_btree *left;
	struct s_btree *right;
	void		*item;
} t_btree;

t_btree *btree_create_node(void *item)
{
	t_btree *node;
	node = (t_btree*)malloc(sizeof(t_btree));
	if (node)
	{
		node->item = item;
		node->left = 0;
		node->right = 0;
	}
	return (node);
}

int ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int ft_btree_level_count(t_btree *root)
{
	int count;
	count = 0;
	if (root == 0)
		return (0);
	if (root->left)
		count = ft_max(count, ft_btree_level_count(root->left));
	if (root->right)
		count = ft_max(count, ft_btree_level_count(root->right));
	return (count + 1);
}

void call(t_btree *root, int current_level, int *levels, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int is_first_item;
	is_first_item = 1;
	if (levels[current_level] == 1)
		is_first_item = 0;
	else
		levels[current_level] = 1;
	applyf(root->left, current_level, is_first_item);
	if (root->left)
		call(root->left, current_level + 1, levels, applyf);
	if (root->right)
		call(root->right, current_level + 1, levels, applyf);
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int count;
	int *levels;
	int i;
	if (root == 0)
		return ;
	count = ft_btree_level_count(root);
	if (!(levels = (int*)malloc(sizeof(int) * count)))
		return ;
	i = 0;
	while (i < count)
		levels[i++] = 0;
	call(root, 0, levels, applyf);
}

void print_item(char item, int current_level, int is_first_elem)
{
    printf("item = %c, level = %d, first = %d\n", item, current_level, is_first_elem);
}

void apply_function(void *item, int current_level, int is_first_elem)
{
	printf("item: %s, current level: %d, is first element: %d\n", (char *)item, current_level, is_first_elem);
}
int main()
{
    t_btree *root = btree_create_node("Root");
    root->left = btree_create_node("Left Child");
    root->right = btree_create_node("Right Child");
    root->left->left = btree_create_node("Left Left Grandchild");
    root->left->right = btree_create_node("Left Right Grandchild");
    root->right->left = btree_create_node("Right Left Grandchild");
    root->right->right = btree_create_node("Right Right Grandchild");

    btree_apply_by_level(root, apply_function);

    return 0;
}

/*

La fonction btree_create_node est utilisée pour créer un nouveau nœud de l'arbre binaire. Elle prend un argument de 
type void *item qui est l'objet à stocker dans le nœud. La fonction alloue de la mémoire pour le nouveau nœud en 
utilisant la fonction malloc et initialise les champs item, left et right avec les valeurs fournies. 
Le champ item contient l'objet stocké, left est un pointeur sur le sous-arbre gauche et right est un pointeur sur 
le sous-arbre droit. La fonction retourne un pointeur sur le nouveau nœud.

Fonction ft_btree_level_count(t_btree *root) :
Cette fonction retourne le nombre de niveaux dans l'arbre binaire donné en entrée. Elle parcourt l'arbre récursivement, 
en comparant les niveaux des fils gauche et droit pour trouver le niveau le plus élevé. Le nombre de niveaux est donné 
par la somme du niveau maximum trouvé + 1.

Fonction 
call(t_btree *root, int current_level, int *levels, void (*applyf)(void *item, int current_level, int is_first_elem)) :
Cette fonction récursive effectue un parcours en profondeur de l'arbre binaire donné en entrée. Elle définit la 
fonction applyf à appeler pour chaque noeud de l'arbre. Elle définit également le niveau actuel, qui est incrémenté 
à chaque fois que la fonction s'appelle pour un fils gauche ou droit. La variable levels est utilisée pour déterminer 
si un noeud donné est le premier élément à un niveau donné. Si le niveau est défini à 1, cela signifie que 
le noeud actuel n'est pas le premier élément, sinon, il est défini à 1 pour désigner le premier élément.

Fonction btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem)) :
Cette fonction parcourt l'arbre binaire donné en entrée en appelant la fonction applyf pour chaque noeud en fonction 
de son niveau. Elle commence par trouver le nombre total de niveaux dans l'arbre en utilisant la fonction 
ft_btree_level_count(). Elle initialise ensuite un tableau de niveaux qui sera utilisé pour déterminer si un noeud est 
le premier élément à un niveau donné. Enfin, elle appelle la fonction call() pour effectuer le parcours en 
profondeur de l'arbre.

Fonction print_item(char item, int current_level, int is_first_elem) :
Cette fonction est utilisée pour imprimer un élément de l'arbre binaire, qui est donné en entrée sous forme de 
caractère. Elle imprime également le niveau actuel et si l'élément est le premier de ce niveau ou non.

La fonction apply_function est une fonction de callback utilisée par la fonction btree_apply_by_level. Elle est 
appelée pour chaque nœud d'un arbre binaire pour le traitement du nœud. La fonction apply_function prend trois arguments :

item : C'est un pointeur vers l'élément stocké dans le nœud actuel
current_level : C'est le niveau actuel du nœud dans l'arbre binaire
is_first_elem : C'est un booléen qui indique si le nœud actuel est le premier élément de son niveau
Dans ce cas, apply_function affiche les informations sur l'élément actuel. Les informations sont le contenu de 
l'élément (casté en chaîne de caractères), le niveau actuel du nœud dans l'arbre binaire et si le nœud actuel est le 
premier élément de son niveau.

*/
