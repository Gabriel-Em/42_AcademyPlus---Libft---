/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:37:02 by gpop              #+#    #+#             */
/*   Updated: 2017/12/07 20:13:38 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleanup(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		ft_memdel((void**)&lst);
		lst = temp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*new_list;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = f(lst);
	new_list = ft_lstnew(temp->content, temp->content_size);
	if (new_list == NULL)
		return (NULL);
	node = new_list;
	while (lst->next)
	{
		lst = lst->next;
		temp = f(lst);
		node->next =
			ft_lstnew(temp->content,
					temp->content_size);
		if
			(node->next
			 == NULL)
			{
				cleanup(new_list);
				return
					(NULL);
			}
		node
			=
			node->next;
	}
	return
		(new_list);
}
