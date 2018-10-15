/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 08:59:42 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/30 08:59:46 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	i;
	char			*out;

	i = ABS(n);
	len = 0;
	if (n < 0 || n == 0)
		len = 1;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	if (!(out = ft_strnew(len)))
		return (NULL);
	i = ABS(n);
	while (--len > -1)
	{
		out[len] = ABS(i) % 10 + 48;
		i /= 10;
	}
	if (n < 0)
		out[0] = '-';
	return (out);
}
