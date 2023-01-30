char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	/*
	if (nb == 0)
		return (0);
	if (src == 0)
		return (0);
	if (dest == 0)
		return (src);
	*/
	if (nb == 0 || src == 0)
		return (0);
	else if (dest == 0)
		return (src);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

#include<stdio.h>
int main(void)
{
	unsigned int nb = 10;
	char src[] = "je pense lacher un gros étron - Jean Marie Bigard";
	char dest[] = "j'ai le cigare au bout des lèvres ";
	printf("%s\n", ft_strncat(dest, src, nb));
	return (0);
}
