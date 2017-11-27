#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len_dst;

	len_dst = 0;
	while (dst[len_dst] != '\0' && len_dst < size)
		len_dst++;
	if (len_dst == size)
		return (size + ft_strlen(src));
	i = len_dst;
	while (i < size - 1 && src[i - len_dst] != '\0')
	{
		dst[i] = src[i - len_dst];
		i++;
	}
	dst[i] = '\0';
	return(len_dst + ft_strlen(src));
}
