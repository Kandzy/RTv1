/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:02:11 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 19:02:13 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*substring;

	if (s)
	{
		i = 0;
		substring = ft_strnew(len);
		if (substring == NULL)
			return (NULL);
		while (i < len)
		{
			substring[i] = s[start + i];
			i++;
		}
		return (substring);
	}
	return (NULL);
}
