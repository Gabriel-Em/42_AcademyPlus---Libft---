/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:41:20 by gpop              #+#    #+#             */
/*   Updated: 2017/11/27 19:41:54 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dest_ptr;
	size_t			i;

	src_ptr = (unsigned char*)src;
	dest_ptr = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		if (src_ptr[i] == c)
			return ((void*)(dest_ptr + i + 1));
		i++;
	}
	return (NULL);
}
