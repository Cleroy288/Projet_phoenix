#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define EVEN(nbr) (nbr % 2 ? 0 : 1)
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0

typedef int	t_bool;
#endif
/*
Ce fichier est un header en C appelé "FT_BOOLEAN_H". 
C'est un fichier d'en-tête qui peut être inclus dans d'autres programmes pour les aider à utiliser 
les définitions, les types de données et les fonctions déclarées dans ce fichier.

Le code définit quelques macros qui peuvent être utilisées pour représenter des booléens (TRUE et FALSE) 
et des fonctions mathématiques (EVEN). Il définit également des messages pour une utilisation ultérieure 
dans le programme principal.

Il utilise également la directive "#define" pour définir des constantes qui peuvent être utilisées par 
le reste du programme. Cela permet de remplacer toutes les occurrences de ces constantes par leurs 
valeurs respectives lors de la compilation.

Enfin, le code définit un type de données appelé "t_bool", qui peut être utilisé pour déclarer des 
variables booléennes.

L'utilisation de ce fichier d'en-tête permettra au programme principal de ne pas avoir à répéter 
les définitions et les fonctions déclarées ici pour chaque utilisation, ce qui améliore la lisibilité 
et la maintenance du code.

La syntaxe utilisée "nbr % ?" est un opérateur ternaire en C. C'est un raccourci pour écrire une 
condition simple en une seule ligne.

Dans ce cas précis, l'expression (nbr % 2 ? 0 : 1) signifie que si le reste de la division de "nbr" 
par 2 est égal à 0, alors la valeur renvoyée sera 1, sinon, la valeur renvoyée sera 0.

L'opérateur ternaire se compose de 3 parties : la condition (nbr % 2), le résultat si la condition 
est vraie (0) et le résultat si la condition est fausse (1). Le symbole "?" est utilisé pour séparer 
la condition du résultat et les ":" sont utilisés pour séparer les deux résultats possibles.

//////////////////////////

Ce bout de code définit un fichier header en C appelé "FT_BOOLEAN_H". Les fichiers header en C contiennent 
des définitions de fonctions, de constantes, de variables, etc. qui peuvent être utilisées dans d'autres 
fichiers source C. Les fichiers header sont généralement inclus en utilisant la directive #include dans 
les fichiers source correspondants.

Les premières lignes définissent un préprocesseur, qui est une macro utilisée pour vérifier si le 
fichier header a déjà été inclus. Si ce n'est pas le cas, le fichier header est inclus en définissant 
la macro "FT_BOOLEAN_H".

La ligne 5 inclut le fichier header "unistd.h", qui fournit des fonctions standard pour la gestion 
des entrées/sorties, des processus, etc.

Les lignes 7 à 9 définissent des constantes booléennes TRUE et FALSE avec les valeurs respectives 1 et 0.

La ligne 11 définit une macro appelée EVEN qui prend un nombre en entrée et renvoie 1 si ce nombre est 
pair, sinon 0. Cette macro utilise l'opérateur modulo % pour déterminer si un nombre est pair ou non. 
Si le nombre est pair, le reste de la division par 2 sera 0, ce qui signifie que le résultat de l'expression 
nbr % 2 sera égal à 0. La macro utilise ensuite le ternaire ? pour renvoyer 1 ou 0 en fonction de la 
valeur de nbr % 2.

Les lignes 12 et 13 définissent les constantes EVEN_MSG et ODD_MSG qui contiennent des chaînes de 
caractères qui peuvent être utilisées pour afficher un message correspondant au nombre pair ou impair 
d'arguments.

La ligne 14 définit la constante SUCCESS avec la valeur 0.

Enfin, la ligne 17 définit un type alias appelé t_bool pour le type entier, ce qui permet d'utiliser 
le type t_bool au lieu d'int pour déclarer des variables booléennes.

*/
