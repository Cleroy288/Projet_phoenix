/*
encore une fois 2 maniers de faire, mais entre nous vou svoyez bine que les 2 sont clairment les meme 

La chaine renvoi 1 quand la string est vide, est -ce juste ou non ? A vous de voir
*/
int	ft_str_is_alpha(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{	
		if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
			return (0);
	i++;
	}
	return (1);
}

/*
int main(void)
{
	char str[] = "Jesuiscontet";
	ft_str_is_alpha(str);
	return (0);
}
*/
/*
int	ft_str_is_alpha(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			return (0);
		++i;
	}
	return (1);
}
*/
#include <stdio.h>
int main()
{
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[] = "abcdefghijklmnopqrstuvwxyz";
	char c[] = "contientPasSeuLementDesLettres[";
	char d[] = "0contientpasSeuLementDeLettres";
	char e[] = "salut, COMMENT tU v7As ? 42mots quarante-deux; cinquante+et+un";

	printf("%d\n", ft_str_is_alpha(a));
	printf("%d\n", ft_str_is_alpha(b));
	printf("%d\n", ft_str_is_alpha(c));
	printf("%d\n", ft_str_is_alpha(d));
	printf("%d\n", ft_str_is_alpha(e));
	return (0);
}

/*
#include <stdio.h>
int ft_str_is_alpha(char *str);

int main(void)
{
	char str[] = "salut, COMMENT tU v7As ? 42mots quarante-deux; cinquante+et+un";
//	char str[] = "";
//	printf("%d \n", str);
	printf("%d", ft_str_is_alpha(str));
	return (0);
}
*/
