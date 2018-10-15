/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:16:34 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/27 14:16:36 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_exeption_strnstr(const char *haystack, const char *needle)
{
	if (*haystack == '\0' && *needle == '\0')
		return (1);
	if (*haystack == ' ' && *needle == '\0')
		return (1);
	if (*needle == '\0' && *haystack != '\0' && *haystack != ' ')
		return (1);
	return (0);
}

char			*ft_strnstr(const char *haystack, const char *needle, size_t k)
{
	size_t	n;
	size_t	i;

	i = 0;
	if (ft_exeption_strnstr(haystack, needle))
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		n = 0;
		if (haystack[i] == needle[n] && i < k)
		{
			while (haystack[i + n] == needle[n] && i + n < k)
			{
				n++;
				if (needle[n] == '\0')
					return ((char*)(haystack + i));
			}
		}
		i++;
	}
	return (NULL);
}
