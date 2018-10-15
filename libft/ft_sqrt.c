/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:26:54 by dkliukin          #+#    #+#             */
/*   Updated: 2017/11/08 15:26:56 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double x)
{
	double	s;
	double	t;
	double	mod;

	if (x < 0)
		return (0);
	s = 0.5 * x;
	t = s;
	s = (s + x / s) * 0.5;
	mod = s - t;
	while ((ABS(mod) / s) > 0.000001)
	{
		t = s;
		s = (s + x / s) * 0.5;
		mod = s - t;
	}
	return (s);
}
