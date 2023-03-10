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

La fonction btree_create_node est utilis??e pour cr??er un nouveau n??ud de l'arbre binaire. Elle prend un argument de 
type void *item qui est l'objet ?? stocker dans le n??ud. La fonction alloue de la m??moire pour le nouveau n??ud en 
utilisant la fonction malloc et initialise les champs item, left et right avec les valeurs fournies. 
Le champ item contient l'objet stock??, left est un pointeur sur le sous-arbre gauche et right est un pointeur sur 
le sous-arbre droit. La fonction retourne un pointeur sur le nouveau n??ud.

Fonction ft_btree_level_count(t_btree *root) :
Cette fonction retourne le nombre de niveaux dans l'arbre binaire donn?? en entr??e. Elle parcourt l'arbre r??cursivement, 
en comparant les niveaux des fils gauche et droit pour trouver le niveau le plus ??lev??. Le nombre de niveaux est donn?? 
par la somme du niveau maximum trouv?? + 1.

Fonction 
call(t_btree *root, int current_level, int *levels, void (*applyf)(void *item, int current_level, int is_first_elem)) :
Cette fonction r??cursive effectue un parcours en profondeur de l'arbre binaire donn?? en entr??e. Elle d??finit la 
fonction applyf ?? appeler pour chaque noeud de l'arbre. Elle d??finit ??galement le niveau actuel, qui est incr??ment?? 
?? chaque fois que la fonction s'appelle pour un fils gauche ou droit. La variable levels est utilis??e pour d??terminer 
si un noeud donn?? est le premier ??l??ment ?? un niveau donn??. Si le niveau est d??fini ?? 1, cela signifie que 
le noeud actuel n'est pas le premier ??l??ment, sinon, il est d??fini ?? 1 pour d??signer le premier ??l??ment.

Fonction btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem)) :
Cette fonction parcourt l'arbre binaire donn?? en entr??e en appelant la fonction applyf pour chaque noeud en fonction 
de son niveau. Elle commence par trouver le nombre total de niveaux dans l'arbre en utilisant la fonction 
ft_btree_level_count(). Elle initialise ensuite un tableau de niveaux qui sera utilis?? pour d??terminer si un noeud est 
le premier ??l??ment ?? un niveau donn??. Enfin, elle appelle la fonction call() pour effectuer le parcours en 
profondeur de l'arbre.

Fonction print_item(char item, int current_level, int is_first_elem) :
Cette fonction est utilis??e pour imprimer un ??l??ment de l'arbre binaire, qui est donn?? en entr??e sous forme de 
caract??re. Elle imprime ??galement le niveau actuel et si l'??l??ment est le premier de ce niveau ou non.

La fonction apply_function est une fonction de callback utilis??e par la fonction btree_apply_by_level. Elle est 
appel??e pour chaque n??ud d'un arbre binaire pour le traitement du n??ud. La fonction apply_function prend trois arguments :

item : C'est un pointeur vers l'??l??ment stock?? dans le n??ud actuel
current_level : C'est le niveau actuel du n??ud dans l'arbre binaire
is_first_elem : C'est un bool??en qui indique si le n??ud actuel est le premier ??l??ment de son niveau
Dans ce cas, apply_function affiche les informations sur l'??l??ment actuel. Les informations sont le contenu de 
l'??l??ment (cast?? en cha??ne de caract??res), le niveau actuel du n??ud dans l'arbre binaire et si le n??ud actuel est le 
premier ??l??ment de son niveau.

*/
