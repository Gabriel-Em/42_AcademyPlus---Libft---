/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcutuntil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 18:35:53 by gpop              #+#    #+#             */
/*   Updated: 2018/01/05 18:37:54 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcutuntil(char **src, int c)
{
	int		i;
	char	*newstr;

	if (src == NULL || *src == NULL)
		return (NULL);
	i = 0;
	while ((*src)[i] != '\0' && (*src)[i] != (unsigned char)c)
		i++;
	if (!(newstr = ft_strnew(i)))
		return (NULL);
	ft_strncat(newstr, *src, i);
	if ((*src)[i] == '\0' || (*src)[i + 1] == '\0')
		*src = ft_strshorten(src, 0, 0);
	else
		*src = ft_strshorten(src, i + 1, ft_strlen(*src) - i - 1);
	return (newstr);
}
