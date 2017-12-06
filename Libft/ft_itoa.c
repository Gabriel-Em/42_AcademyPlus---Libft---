/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:12:36 by gpop              #+#    #+#             */
/*   Updated: 2017/12/05 22:13:50 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_of_digits(int n)
{
	int count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		no_of_digits;
	int		k;

	sign = 0;
	if (n < 0)
		sign = 1;
	no_of_digits = get_number_of_digits(n);
	str = ft_strnew(no_of_digits + sign);
	if (str == NULL)
		return (NULL);
	if (sign)
		str[0] = '-';
	k = no_of_digits + sign - 1;
	while (k >= sign)
	{
		if (sign)
			str[k--] = (n % 10 * -1) + '0';
		else
			str[k--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
