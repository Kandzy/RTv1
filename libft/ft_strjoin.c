/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:27:35 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 19:27:37 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*constr;

	if (!s1 || !s2)
		return (NULL);
	else
	{
		constr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (constr == NULL)
			return (NULL);
		ft_strcpy(constr, s1);
		ft_strcat(constr, s2);
	}
	return (constr);
}
