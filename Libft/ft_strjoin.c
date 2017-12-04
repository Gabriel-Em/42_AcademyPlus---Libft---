#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t  len_s1;
    size_t  len_s2;
    size_t  i;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    str = (char*)malloc((len_s1 + len_s2 + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (i < len_s1)
    {
        str[i] = s1[i];
        i++;
    }
    while (i - len_s1 < len_s2)
    {
        str[i] = s2[i - len_s1];
        i++;
    }
    str[i] = '\0';
    return (str);
}
