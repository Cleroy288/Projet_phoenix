int	ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>
int    main(void)
{
    int islower;
    char a[] = "BONJURLESGENS";
    islower = ft_str_is_lowercase(a);
    printf("%d\n", islower);
}
