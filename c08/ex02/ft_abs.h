#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(value) (((value) < 0) ? -value : value)

#endif
/*
Ce code est un en-tête de fichier en C qui définit une macro appelée ABS.

La première ligne, #ifndef FT_ABS_H, vérifie si la macro FT_ABS_H a déjà été définie. 
Si elle n'a pas été définie, le code suivant est inclus.

La deuxième ligne, #define FT_ABS_H, définit la macro FT_ABS_H.

La troisième ligne, #define ABS(value), définit la macro ABS qui calcule la valeur absolue d'un nombre. 
Cette macro utilise un opérateur ternaire (?:) pour déterminer si la valeur est négative ou non. 
Si la valeur est négative, elle est négative. sinon, la valeur reste inchangée.

La dernière ligne, #endif, marque la fin de la définition de la macro.

Un macro est un court segment de code défini par une constante de substitution et associé à une expression. 
Les macros sont généralement utilisés pour améliorer la lisibilité du code et 
pour éviter la répétition de code.

Dans ce cas précis, le macro ABS défini une expression qui calcule la valeur absolue d'un nombre. 
La syntaxe générale de la macro ABS est la suivante:

#define ABS(value) (((value) < 0) ? -value : value)

L'expression ABS défini que si value est inférieur à zéro, retourne la valeur négative de value. 
Sinon, retourne la valeur de value inchangée. Le macro ABS est évalué lors de la préprocessing et 
remplacera toutes les occurrences de ABS(value) par cette expression.

Ainsi, lors de la compilation, cette expression est évaluée pour chaque occurrence de ABS(value) 
pour calculer la valeur absolue d'un nombre.

*/
