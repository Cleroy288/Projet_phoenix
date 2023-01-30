/*
oui il ya 2 main, pour quoi ? Un compare la fonction ft a la vraie fonction, lautre imprime dest et src

Pour quoi j'ai pas fusionné les 2? Je n'ai pas que ca a faire ! J'ai aqua-zumba
*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	if (size == 0)
		return (0);
	while (src[count] != '\0')
		++count;
	if (count == 0)
		return (0);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}
/*
#include <stdio.h>
int main(void)
{
	unsigned int  size;
	char src[] = "cest de la bonne patate douce";
	char dest[] ="";
	
	ft_strlcpy(src, dest, size);
	printf ("%s\n", src);
	printf("%s\n", dest);
	return (0);
}
*/

#include <stdio.h>
#include <string.h>

int		main(void)
{
	int i;
	char	dest[50];
	char *src;
	int	size;
	
	src = "be like water my friend";
	i = 0;
	while (src[i] != '\0')
		i++;
	size = 29;
	printf("%d\n", ft_strlcpy(dest, src, size));
	printf(".%s.\n\n", dest);
	printf("%lu\n", strlcpy(dest, src, size));
	printf(".%s.\n\n", dest);
}
