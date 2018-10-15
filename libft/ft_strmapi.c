/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:35:38 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 17:35:40 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*nstr;
	unsigned int		lens;
	unsigned int		i;

	if (s != NULL && f != NULL)
	{
		lens = ft_strlen(s);
		nstr = ft_strnew(sizeof(char) * lens);
		if (nstr == NULL)
			return (NULL);
		i = 0;
		while (i < lens)
		{
			nstr[i] = f(i, s[i]);
			i++;
		}
		return (nstr);
	}
	return (0);
}
