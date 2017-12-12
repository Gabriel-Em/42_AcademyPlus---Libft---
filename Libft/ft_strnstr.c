/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 20:10:43 by gpop              #+#    #+#             */
/*   Updated: 2017/12/12 03:55:24 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	int		i;

	len_little = ft_strlen(little);
	if (len_little == '\0')
		return ((char*)big);
	i = 0;
	while (big[i] != '\0' && i <= (int)(len - len_little))
	{
		if (big[i] == little[0])
			if (!ft_strncmp(big + i, little, len_little))
				return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
