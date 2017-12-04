#include "libft.h"

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *str;
    size_t i;

    if (s == NULL)
        return (NULL);
    str = (char*)malloc((len + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
