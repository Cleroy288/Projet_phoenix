char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
	{
		src[i] = dest[i];
		i++;
	}
	src[i] = dest[i];
	return (dest);
}


/*
You like my ENGLISH ???

char    *ft_strcpy(char *s1, char *s2)
  {
      int i;

      i = 0;
      while (s2[i])
      {
          s1[i] = s2[i]; // so this will make s1 = to whatever s2 is looping through the string
          i++;
      }
      s1[i] = s2[i];  // now that we are finsihing looping though s1[i] will equal s2[i]
      return (s1);
  }
*/
#include <stdio.h>
int main(void)
{
	char str1[] = "fla";
	char str2[] = "flila";
	printf("%s\n", str1);   // displaying what str1 is before ft_strcpy is used on it
	ft_strcpy(str1, str2);  // calling out functtion ft_strcpy on the strings
	printf("%s\n", str1);  // str1 should now become str2
	return (0);
}
