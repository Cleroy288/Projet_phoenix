#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return;
	while (str[i])
	{
		write (1, &str[i], 1);
	}
}
