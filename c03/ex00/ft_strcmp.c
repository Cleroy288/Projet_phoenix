
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if ((s1[i] == 0) || (s2[i] == 0))
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>

int main (void)
{
	char s1[] = "je suis pas content";
	char s2[] = "je suis content";
	
	printf("le résultat est : %d\n",ft_strcmp(s1, s2));
	return (0);
}

