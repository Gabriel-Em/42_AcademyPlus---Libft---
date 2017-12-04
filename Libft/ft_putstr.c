#include "libft.h"

void    ft_putstr(char const *s)
{
    int i;
    
    if (s != NULL)
    {
        i = 0;
        while (s[i] != '\0')
            ft_putchar(s[i++]);
    }
}
