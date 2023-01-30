int	ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			return (0);
		}
		else
			i++;
	}
	return (1);
}

#include <stdio.h>
int    main(void)
{
    int islower;

    char a[] = "bonj or";
    islower = ft_str_is_lowercase(a);
    printf("%d\n", islower);
}

