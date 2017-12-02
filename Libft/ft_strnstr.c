/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 20:10:43 by gpop              #+#    #+#             */
/*   Updated: 2017/12/02 01:45:00 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t len_little;
	size_t i;

	len_little = ft_strlen(little);
	if (len_little == '\0')
		return ((char*)big);
	if (len_little > len)
		len_little = len;
	i = 0;
	while (i <= len - len_little)
	{
		if (big[i] == little[0])
			if (!ft_strncmp(big + i, little, len_little))
				return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
