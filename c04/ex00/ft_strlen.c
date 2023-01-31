int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

#include <stdio.h>
int	main(void)
{
	char	str[] = "tu connais la différence entre la tour eiffel et un prisonnier ?";
	char	str2[] = "la tour eifel est en acier, le prisonnier est en taule";
	printf("%u\n", ft_strlen(str));
	printf("%d\n", ft_strlen(str2));
	return (0);
}
