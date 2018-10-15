/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:50:40 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 19:50:43 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*trim;
	int		n;
	int		l;

	if (!s)
		return (NULL);
	i = 0;
	n = 0;
	l = ft_strlen(s);
	while (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n')
		l--;
	if (l != 0)
	{
		while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
			n++;
	}
	trim = ft_strnew(l - n);
	while (n != l && trim)
	{
		trim[i] = s[n];
		n++;
		i++;
	}
	return (trim);
}
