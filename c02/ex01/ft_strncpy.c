char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <stdio.h>

int main()
{
     char dest[] = "test de chaine";
     char *src = "abc";

     ft_strncpy(dest, src, 6);
     printf("%s\n", dest);
     return 0;
}
