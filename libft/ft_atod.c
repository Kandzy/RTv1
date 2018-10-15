/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:28:32 by dkliukin          #+#    #+#             */
/*   Updated: 2017/11/06 16:28:35 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		white_space(const char *str, int *i)
{
	int		n;

	n = 0;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t' ||
		str[n] == '\v' || str[n] == '\r' || str[n] == '\f')
		n++;
	*i = n;
}

static double	atof_g(char *str, int *i)
{
	int		j;
	double	number;
	double	next_part;
	double	k;

	j = *i;
	k = 1;
	number = 0;
	next_part = 0;
	while (str[j] != '\0' && str[j] >= '0' && str[j] <= '9')
	{
		number *= 10;
		number += str[j] - '0';
		j++;
	}
	if (str[j++] == '.')
		while (str[j] != '\0' && str[j] >= '0' && str[j] <= '9')
		{
			next_part *= 10;
			next_part += str[j] - '0';
			j++;
			k *= 10;
		}
	number = (number * k + next_part) / k;
	return (number);
}

double			ft_atod(char *str)
{
	double		number;
	int			i;
	int			help;

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
	number = atof_g(str, &i);
	return (number * help);
}
