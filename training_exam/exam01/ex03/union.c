/*

Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

*/

#include <unistd.h>

int	check_dub(char *str, char c, int pos)
{
	int	i = 0;
	
	while (i < pos)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *str1, char *str2)
{
	int	i = 0;
	int	j;

	while (str1[i])
	{
		if  (check_dub(str2, str1[i], i) == 0)
			write (1, &str1[i], 1);
		i++;
	}
	j = i;
	i = 0;
	while (str2[i])
	{
		if (check_dub(str2, str2[i], i) == 0)
		{
			if (check_dub(str1, str1[i], j) == 1)
				write (1, &str2[i], 1);
		}
		i++;
	}
}


int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write (1, "\n", 1);

}
