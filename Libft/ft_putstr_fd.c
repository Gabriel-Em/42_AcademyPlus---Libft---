#include "libft.h"

void    ft_putstr_fd(char const *s, int fd)
{
    int i;

    if(s != NULL)
    {
        i = 0;
        while (s[i] != '\0')
            ft_putchar_fd(s[i++], fd);
    }
}
