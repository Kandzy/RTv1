/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:26:44 by dkliukin          #+#    #+#             */
/*   Updated: 2017/11/08 15:26:46 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_toa(long long num, int len)
{
	char	*str;

	str = (char*)malloc(len + 2);
	str[len + 1] = '\0';
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}

char		*ft_dtoa(long double number)
{
	char		*str;
	long long	a;
	long long	b;
	int			help;

	help = 0;
	a = (long long)number;
	b = (long long)((number - a) * 1000000);
	str = (char*)malloc(ft_lenofnum(a) + ft_lenofnum(b) + 3);
	str[0] = '\0';
	if (number < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		a = -a;
		b = -b;
		help = 1;
	}
	ft_strcat(str, ft_toa(a, ft_lenofnum(a)));
	a = ft_lenofnum(a);
	str[a + help] = '.';
	str[a + 1 + help] = '\0';
	ft_strcat(str, ft_toa(b, ft_lenofnum(b)));
	return (str);
}
