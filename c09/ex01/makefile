SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS = $(addprefix $(PRE), $(SRC))
OBJS = $(SRCS:.c=.o)
PRE = ./srcs/
HEAD = ./includes/
NAME = libft.a
AR = ar rc
RM = rm -f
LIB = ranlib
GCC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(GCC) $(CFLAGS) -c -I $(HEAD) $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(LIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

/*
Ce script Makefile permet de construire une bibliothèque statique appelée libft.a à partir de cinq fichiers sources .c : ft_putchar.c, ft_swap.c, ft_putstr.c, ft_strlen.c, et ft_strcmp.c.

Les variables définies en début de script représentent les noms de fichiers et les options utilisées pour construire la bibliothèque.

Les commandes ar rc et ranlib sont utilisées pour archiver et indexer les fichiers objets pour créer la bibliothèque statique.

L'option -I dans la règle .c.o permet d'inclure les fichiers d'en-tête se trouvant dans le répertoire ./includes/.

Les commandes all, clean, fclean, et re permettent respectivement de construire la bibliothèque, de supprimer les fichiers objets, de supprimer la bibliothèque et les fichiers objets, et de tout reconstruire à partir des fichiers sources.

Enfin, la déclaration .PHONY indique à Make que les cibles all, clean, fclean, et re ne sont pas des fichiers réels et doivent toujours être exécutées, même si un fichier portant le même nom existe dans le répertoire de travail.
*/
