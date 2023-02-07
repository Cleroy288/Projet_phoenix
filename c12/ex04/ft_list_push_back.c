#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*created;

	created = NULL;
	created = malloc(sizeof(t_list));
	if (created)
	{
		created->data = data;
		created->next = NULL;
	}
	return (created);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
    t_list	*new_elem;
    t_list	*current;
    
    new_elem = ft_create_elem(data); // On crée un nouvel élément avec les données passées en paramètre.
    current = *begin_list; // On récupère l'adresse du début de la liste.
    if (*begin_list == NULL) // Si la liste est vide, on renvoie directement le nouvel élément.
        *begin_list = new_elem;
    else
    {
        while (current->next != NULL) // Sinon on parcours la liste jusqu'à arriver à la fin.
            current = current->next;
        current->next = new_elem; // On ajoute le nouvel élément à la fin de la liste.
    }
}


int	main(int argc, char **argv)
{
	t_list	elem1, elem2, elem3, *begin;

	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = 0;

	elem1.data = "toto";
	elem2.data = "tata";
	elem3.data = "tutu";

	ft_list_push_back(&begin, argv[1]);
	while (begin)
	{
		printf("%s\n", begin->data);
		begin = begin->next;
	}
}

