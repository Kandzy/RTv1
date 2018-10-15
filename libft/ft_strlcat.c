/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:53:55 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/26 15:53:58 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	if (srclen < dstsize - dstlen)
	{
		ft_memcpy(dst + dstlen, src, srclen);
		dst += dstlen + srclen;
	}
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
		dst += dstsize - 1;
	}
	*dst = '\0';
	return (srclen + dstlen);
}
