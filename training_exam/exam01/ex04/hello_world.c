#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_alphabet(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else if (c >= 65 && c <= 90)
		return (0);
}


unsigned int sleeep(unsigned int seconds);

void	ftwrite (char *s1)
{
	int	i = 0;
	int	j;
	char	tmp;
	char 	mini[] = "abcdefghijklmnopqrstuvwxyz ";
	char	maj[] = "ABVDEFGHIJKLMNOPQRSTUVWXYZ ";

	while (s1[i])
	{
		j = 0;
		if (is_alphabet(s1[i]) == 1)
		{
			while (s1[i] != mini[j])
			{
				write (1, s1, i);
				write (1, &mini[j], 1);
				write (1, "\n", 1);
				j++;
			}
			write (1, s1, i);
			write (1, &mini[j], 1);
			write (1, "\n", 1);
		//	usleep(75000);
		}
		else if (is_alphabet(s1[i]) == 0)
		{
			while (s1[i] != maj[j])
			{
				write (1, s1, i);
				write (1, &maj[j], 1);
				write (1, "\n", 1);
				j++;
			}
			write (1, s1, i);
			write (1, &maj[j], 1);
			write (1, "\n", 1);
		//	usleep(75000);
		}
		else if (s1[i] == 32)
		{
			write (1, s1, i);
			write (1, " ", 1);
			write (1, "\n", 1);
		}
		else
		{
			if (s1[i] == '!' || s1[i] == '?')
			{
				char c = s1[i];
				write (1, s1, i);
				write (1, &c, 1);
			}
			write (1, "\n", 1);
		}
		usleep(115000);
	i++;
	//usleep(75000);
	}
}

int	main(int argc, char **argv)
{
	//char	str[] = "il nous faut un plan pour reussir la piscine !";
	//char str2[] = "j'ai un plan ; réussir la pisicne ";
	if (argc == 2)
		ftwrite(argv[1]);
}
