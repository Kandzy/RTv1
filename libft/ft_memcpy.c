/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:00:52 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/28 12:17:23 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dist, const void *src, size_t n)
{
	char	*ptr_src;
	char	*ptr_dist;
	int		i;

	i = 0;
	ptr_src = (char*)src;
	ptr_dist = (char*)dist;
	while (n--)
	{
		ptr_dist[i] = ptr_src[i];
		i++;
	}
	return (dist);
}
