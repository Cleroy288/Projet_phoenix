char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == 0)
		return (0);
	if (to_find[j] == 0)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				j++;
				if (!to_find[j])
					return (&str[i]);
			}
		}
	i++;
	}
	return (0);
}
#include <stdio.h>
int	main(void)
{
	char str[] = "je suis content le poulet cest bon";
	char to_find[] = "content";
	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}
