/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 00:15:58 by gpop              #+#    #+#             */
/*   Updated: 2017/12/06 00:45:45 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int *tab, int start, int end)
{
	int pivot;
	int p_index;
	int i;

	pivot = tab[end];
	p_index = start;
	i = start - 1;
	while (++i < end)
		if (tab[i] < pivot)
			ft_swap(tab + i, tab + p_index++, sizeof(int));
	ft_swap(tab + end, tab + p_index, sizeof(int));
	return (p_index);
}

void		ft_quicksort(int *tab, int start, int end)
{
	int p_index;

	if (start < end)
	{
		p_index = partition(tab, start, end);
		ft_quicksort(tab, start, p_index - 1);
		ft_quicksort(tab, p_index + 1, end);
	}
}
