/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshorten.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:11:25 by gpop              #+#    #+#             */
/*   Updated: 2017/12/20 14:24:46 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshorten(char *s, int start, int len)
{
	char *newstr;

	newstr = ft_strsub(s, start, len);
	ft_strdel(&s);
	s = newstr;
	return (s);
}
