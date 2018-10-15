/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:41:05 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 18:41:07 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	if (s1 && s2)
	{
		i = 0;
		while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
	}
	else
		return (0);
	return (1);
}
