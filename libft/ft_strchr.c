/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:00:20 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/26 18:00:22 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == (char)c)
			return ((char*)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char*)str);
	return (NULL);
}
