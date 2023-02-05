#include <stdlib.h>
char	*ft_strdup(char *src)
{
	char	*new;
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	if(! (new = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

#include <stdio.h>

int	main(void)
{
	char	src[] = "alors ta compirs malloc ?!";
	char	*new = ft_strdup(src);
	
	printf("%s\n", new);
	return (0);
}

