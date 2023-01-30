#include <unistd.h>


void	ft_print_alphabet(void)
{
	write (1, "abcdefghijklmnopqrstuvwxyz", 26);
}

int	main()
{
	ft_print_alphabet();
	write (1, "\n", 1);
}
