/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:46:01 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/26 11:56:13 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dist, const char *src)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	while (i < len + 1)
	{
		dist[i] = src[i];
		i++;
	}
	return (dist);
}
