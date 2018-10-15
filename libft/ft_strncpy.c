/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:49:18 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/26 12:49:21 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dist, const char *src, size_t len)
{
	size_t	i;
	size_t	lenofsrc;

	lenofsrc = ft_strlen(src);
	i = 0;
	while (i < len)
	{
		if (i < lenofsrc)
			dist[i] = src[i];
		else
			dist[i] = '\0';
		i++;
	}
	return (dist);
}
