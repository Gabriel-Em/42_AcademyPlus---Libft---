#include "libft.h"

char    *ft_strmap(char const *s, char (*f)(char))
{
    char    *str;
    int     i;

    if (s == NULL || f == NULL)
        return (NULL);
    str = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        str[i] = f(s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}
