/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:27:29 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/27 17:27:32 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(unsigned long long n, int help)
{
	if (n > 9223372036854775807 && help == -1)
		return (0);
	else if (n > 9223372036854775807)
		return (-1);
	else
		return (666);
}

static void		white_space(const char *str, int *i)
{
	int		n;

	n = 0;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t' ||
		str[n] == '\v' || str[n] == '\r' || str[n] == '\f')
		n++;
	*i = n;
}

int				ft_atoi(const char *str)
{
	unsigned long long	number;
	int					i;
	int					help;

	i = 0;
	help = 1;
	number = 0;
	white_space(str, &i);
	if (str[i] == '-')
	{
		help = -1;
		i++;
	}
	if (str[i] == '+' && help != -1)
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	if (check(number, help) != 666)
		return (check(number, help));
	return (number * help);
}
