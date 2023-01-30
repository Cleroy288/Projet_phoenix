
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	/*
	if (size < 0)
		return (0);
	if (size == 0)
		return (0);
	if (src == 0)
		return (0);
	if (dest == 0)
		return (0);
	*/
	if (size < 0 || size == 0 || src == 0 || dest == 0)
		return (0);
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && (i < (size -1)))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + j);
}

#include <stdio.h>

int	main(void)
{
	char r[] = "tu veux du poulet ou pas ? ";
	char t[50] = "ALLLEEEZ HEEEU ";

	printf("%u\n", ft_strlcat(t, r, 50));
	printf ("%s\n" , r);
	printf("%s\n", t);
	return (0);
}
