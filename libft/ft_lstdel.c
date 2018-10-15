/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:07:31 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/31 15:07:32 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lptr;
	t_list	*next_lptr;

	if (!del)
		return ;
	if (alst != NULL)
	{
		lptr = *alst;
		while (lptr)
		{
			next_lptr = lptr->next;
			(*del)(lptr->content, lptr->content_size);
			free(lptr);
			lptr = next_lptr;
		}
		*alst = NULL;
	}
}
