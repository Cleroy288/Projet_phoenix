int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

#include <stdio.h>
int main(void)
{
    char str[] = "j'aime les pates";
    printf("%d\n", ft_strlen(str));
}