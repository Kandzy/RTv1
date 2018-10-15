/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:09:48 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/26 15:09:58 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str1;

	if (!n)
		return (s1);
	str1 = s1;
	while (*str1)
		str1++;
	while (n && *s2)
	{
		*str1++ = *s2++;
		n--;
	}
	*str1 = '\0';
	return (s1);
}
