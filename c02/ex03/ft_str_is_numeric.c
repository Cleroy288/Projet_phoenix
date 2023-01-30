int	ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

#include <stdio.h>
int main()
{
    int result;

    result = ft_str_is_numeric("asdf");
    printf("Result: %d\n", result);

    result = ft_str_is_numeric("QWERTY");
    printf("Result: %d\n", result);

    result = ft_str_is_numeric("asdf1234");
    printf("Result: %d\n", result);

    result = ft_str_is_numeric("000999");
    printf("Result: %d\n", result);

    result = ft_str_is_numeric("");
    printf("Result: %d\n", result);
    
    return 0;
}
