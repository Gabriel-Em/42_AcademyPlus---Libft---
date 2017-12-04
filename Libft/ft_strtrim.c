#include "libft.h"

char    *ft_strtrim(char const *s)
{
    char    *str;
    size_t  i;
    size_t  j;
    int     k;

    if (s == NULL)
        return (NULL);
    i = 0;
    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
        i++;
    j = ft_strlen(s);
    if (i == j)
        return (ft_strnew(0));
    while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
        j--;
    str = ft_strnew(j - i);
    if (str == NULL)
        return (NULL);
    k = 0;
    while (i < j)
        str[k++] = s[i++];
    str[k] = '\0';
    return (str);
}
