/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:23:28 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 16:23:30 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*nstr;
	int		lens;
	int		i;

	if (s != NULL && f != NULL)
	{
		lens = ft_strlen(s);
		nstr = ft_strnew(sizeof(char) * lens);
		if (nstr == NULL)
			return (NULL);
		i = 0;
		while (i < lens)
		{
			nstr[i] = f(s[i]);
			i++;
		}
		return (nstr);
	}
	return (0);
}
