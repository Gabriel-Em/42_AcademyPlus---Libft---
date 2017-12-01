/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 20:10:43 by gpop              #+#    #+#             */
/*   Updated: 2017/12/01 20:10:47 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t len_little;
	size_t limit;
	size_t i;
	size_t j;

	if (*little == '\0')
		return ((char*)big);
	len_little = ft_strlen(little);
	limit = ft_strlen(big);
	if (len < limit)
		limit = len;
	i = 0;
	while (i <= limit - len_little)
	{
		j = 0;
		while (j < len_little && big[i + j] == little[j])
			j++;
		if (j == len_little)
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
