#ifndef FT_H
# define FT_H

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
#endif

/*
Le fichier ".h" en C est un fichier d'en-tête qui contient les prototypes de fonctions 
et les définitions de constantes et de macros utilisées dans un programme.

La syntaxe "#ifndef FT_H" vérifie si la constante FT_H n'a pas été définie auparavant. Si elle 
n'a pas été définie, alors le code suivant sera exécuté.

La syntaxe "#define FT_H" définit la constante FT_H.

Les prototypes de fonctions suivants sont déclarées: ft_putchar, ft_swap, ft_putstr, ft_strlen et ft_strcmp.

La syntaxe "#endif" marque la fin du fichier d'en-tête.

Ce fichier d'en-tête peut être inclus dans d'autres fichiers pour permettre l'utilisation de 
ces fonctions sans devoir les réécrire.

*/
