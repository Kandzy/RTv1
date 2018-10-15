/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:34:40 by dkliukin          #+#    #+#             */
/*   Updated: 2017/11/22 19:35:12 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnllst		*new_gnllst(t_list **lst, int fd)
{
	t_gnllst		*gnllst;
	t_list			*temp;

	temp = *lst;
	while (temp)
	{
		gnllst = (t_gnllst*)(temp->content);
		if (gnllst->fd == fd)
			return (gnllst);
		temp = temp->next;
	}
	gnllst = (t_gnllst*)ft_memalloc(sizeof(t_gnllst));
	gnllst->flow = ft_strnew(BUFF_SIZE);
	gnllst->fd = fd;
	gnllst->rd = BUFF_SIZE;
	temp = ft_lstnew(gnllst, sizeof(t_gnllst));
	ft_memdel((void**)&gnllst);
	ft_lstadd(lst, temp);
	return ((t_gnllst*)temp->content);
}

static void			move_line(t_gnllst *gnllst)
{
	char			*temp;

	temp = ft_strsub(gnllst->flow, ft_strchr(gnllst->flow, '\n')
		- gnllst->flow + 1, ft_strlen(gnllst->flow));
	ft_strdel(&gnllst->flow);
	gnllst->flow = temp;
}

static int			rd_z_ret(char **line)
{
	if (ft_strlen(*line) >= 1)
		return (1);
	return (0);
}

static int			read_line(t_gnllst *gnllst, int fd, char **line)
{
	char			*str;

	str = ft_strnew(BUFF_SIZE);
	while (!(ft_strchr(gnllst->flow, '\n')))
	{
		gnllst->rd = read(fd, str, BUFF_SIZE);
		gnllst->flow = ft_strconcat(gnllst->flow, str);
		str = ft_strnew(BUFF_SIZE);
		if (gnllst->rd <= 0)
			break ;
	}
	if (gnllst->rd == 0)
	{
		*line = ft_strconcat(gnllst->flow, str);
		gnllst->fd = -gnllst->fd;
		return (rd_z_ret(line));
	}
	ft_strdel(&str);
	if (gnllst->rd == -1)
		return (-1);
	*line = ft_strsub(gnllst->flow, 0, ft_strchr(gnllst->flow,
		'\n') - gnllst->flow);
	move_line(gnllst);
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_gnllst		*gnllst;
	int				fail;
	int				clean;

	clean = 0;
	fail = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	gnllst = new_gnllst(&lst, fd);
	if (gnllst->rd == 0)
		clean = 1;
	if (clean == 0)
	{
		if ((fail = read_line(gnllst, fd, line)) != 1)
			return (fail);
		if (fail == 1)
			return (1);
	}
	*line = ft_strnew(0);
	return (0);
}
