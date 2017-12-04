#include "libft.h"

int ft_strequ(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (0);

    if (ft_strcmp(s1, s2))
        return (0);
    return (1);
}
