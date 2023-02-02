/*
Assignment name  : only_z
Expected files   : only_z.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a 'z' character on the standard output.
*/
#include <unistd.h>

int	main()
{
	write (1, "z", 1);
}
