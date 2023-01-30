int	ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] == 127) 
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
    char a[] = "bonjour les çàçè8799";
    islower = ft_str_is_lowercase(a);
    printf("%d\n", islower);
}
