/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:57:23 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/31 15:57:25 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*temp;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(ptr = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	start = ptr;
	temp = f(lst);
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(ptr->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		ptr = ptr->next;
		lst = lst->next;
	}
	return (start);
}
