/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:46:49 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/28 12:46:51 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_src;
	unsigned char		*ptr_dst;

	if (!len)
		return (dst);
	else if (!src && !dst)
		return (NULL);
	ptr_src = (unsigned char*)src;
	ptr_dst = (unsigned char*)dst;
	if (ptr_src < ptr_dst)
	{
		ptr_src = ptr_src + len;
		ptr_dst = ptr_dst + len;
		while (len--)
		{
			ptr_dst--;
			ptr_src--;
			*ptr_dst = *ptr_src;
		}
	}
	else
		ft_memcpy(ptr_dst, ptr_src, len);
	return (dst);
}
