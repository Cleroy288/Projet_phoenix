char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
#include <stdio.h>
 
int  main(void)
{
  char src[] = "Waffles";
  char dst[] = "Pancakes";
 
  printf("%s\n", src);
  printf("%s\n", dst);
 
  ft_strcpy(dst, src);
 
  printf("After copying: %s\n", dst);
}
