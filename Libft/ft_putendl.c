#include "libft.h"

void    ft_putendl(char const *s)
{
    if (s != NULL)
    {
        ft_putstr(s);
        ft_putchar('\n');
    }
}
