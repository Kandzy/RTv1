/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 08:37:35 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/30 08:37:37 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int		res;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	res = n;
	if (res <= 9)
		ft_putchar(res + 48);
	else
	{
		ft_putnbr(res / 10);
		ft_putnbr(res % 10);
	}
}
