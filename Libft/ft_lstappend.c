/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:37:30 by gpop              #+#    #+#             */
/*   Updated: 2017/12/13 22:42:16 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list *list;

	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			list = *alst;
			while (list->next != NULL)
				list = list->next;
			list->next = new;
		}
	}
}
