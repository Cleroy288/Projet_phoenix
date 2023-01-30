
char	 *ft_strupcase(char *str)
{
	int i;

	i = 0;
	if (str  == 0)
		return (0); 
	while (str[i] != '\0')
	{
		if (str[i] > 96 && str[i] < 123)
		{
			str[i] = str[i] - 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

#include <stdio.h>

int main(void)
{
	char str[] = "bon+jou=r%les%anis";
	char *naze = 0;
	printf("string test = %s\n", ft_strupcase(str)); 
	printf("null test = %s\n", ft_strupcase(naze)); 
	return (0);
}

