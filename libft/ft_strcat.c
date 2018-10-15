/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:31:17 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/26 14:31:22 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	int		min;
	int		i;

	min = ft_strlen(str1);
	i = 0;
	while (str2[i])
	{
		str1[min + i] = str2[i];
		i++;
	}
	str1[min + i] = '\0';
	return (str1);
}
