char	*ft_toutestpetit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 91 && str[i] > 64)
		{
			str[i] = str[i] + 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_toutestpetit(str);
	i = 1;
	if (str[i] == 0)
		return (str);
	while (str[i] != '\0')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] = str[0] - 32;
		else if (str[i -1] == ' ')
			str[i] -= 32;
		i++;
	}
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char str[] = "si il faut souffrir pr etre beau toi t'as carrément du froler la mort)";
	char str2[] = "en temps de GU3R3 tu 3est plu70T l4 BOMB& ou le MISSILé";
	ft_strcapitalize(str);
	ft_strcapitalize(str2);
	printf("%s\n", str);
	printf("%s\n", str2);
	return (0);
}
