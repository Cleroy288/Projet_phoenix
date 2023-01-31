#include <unistd.h>

void	ft_another_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	write (1, str, count);
}

int	main(void)
{
	char	str[] = "tu n'a jamais vu le clown qui se cache des gens pas beau ?\n";
	char	str2[] = "n'est pas ?\n";

	ft_another_putstr(str);
	//write (1, "\n", 1);
	ft_putstr(str2);
	
	return (0);
}

