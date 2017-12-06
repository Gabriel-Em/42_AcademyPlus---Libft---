/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:24:06 by gpop              #+#    #+#             */
/*   Updated: 2017/12/06 22:32:41 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char *str)
{
	int c;
	int i;

	if (str == NULL || str[0] == '\0')
		return (0);
	c = 0;
	if (!ft_isspace(str[0]))
		c = 1;
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i - 1]) && !ft_isspace(str[i]))
			c++;
		i++;
	}
	return (c);
}
