int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	if ((((s1[i] || s2[i])) <= 0) || (n <= 0))
		return (0);
	while (s1[i] == s2[i] && i != n)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>
int main(void)
{
	char s1[] = "bonjour";
	char s2[] = "bonjouR";
	unsigned int n = 6;
	printf("voici le résultat : %d\n", ft_strncmp(s1, s2, n));
	return (0);
}
