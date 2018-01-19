/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:03:55 by gpop              #+#    #+#             */
/*   Updated: 2018/01/19 14:39:21 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_stack_el	*retrieve_active_stack(t_list **stack, int fd)
{
	t_list		*node;
	t_stack_el	*active;

	node = *stack;
	while (node)
	{
		if (((t_stack_el*)(node->content))->fd == fd)
			return ((t_stack_el*)node->content);
		node = node->next;
	}
	if (!(active = (t_stack_el*)malloc(sizeof(t_stack_el))) ||
		!(active->str = ft_strnew(0)))
		return (NULL);
	active->fd = fd;
	if (!(node = ft_lstnew(NULL, 0)))
		return (NULL);
	node->content_size = sizeof(active);
	node->content = active;
	ft_lstadd(stack, node);
	return ((t_stack_el*)(node->content));
}

static int			keep_reading(t_stack_el **active)
{
	char	*tmp;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read((*active)->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin((*active)->str, buf);
		ft_strdel(&((*active)->str));
		(*active)->str = tmp;
		if (ft_strchr((*active)->str, '\n'))
			return (1);
	}
	if (ret == 0 && ft_strlen((*active)->str) > 0)
		return (1);
	return (ret);
}

static void			free_stack_el(t_list **stack, int fd)
{
	t_list	*node;
	t_list	*prev;

	node = *stack;
	prev = NULL;
	while (node)
	{
		if (((t_stack_el*)(node->content))->fd == fd)
		{
			if (prev)
				prev->next = node->next;
			else
				*stack = (*stack)->next;
			ft_strdel(&(((t_stack_el*)(node->content))->str));
			ft_memdel((void**)&node);
			break ;
		}
		prev = node;
		node = node->next;
	}
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*stack;
	t_stack_el		*active;
	int				ret;

	if (fd < 0 || !line || read(fd, 0, 0) < 0 ||
		!(active = retrieve_active_stack(&stack, fd)))
		return (-1);
	if (ft_strchr(active->str, '\n'))
	{
		*line = ft_strcutuntil(&(active->str), '\n');
		return (1);
	}
	ret = keep_reading(&active);
	if (ret == 1)
		*line = ft_strcutuntil(&(active->str), '\n');
	else
		free_stack_el(&stack, fd);
	return (ret);
}
