/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtnarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:26:29 by dkliukin          #+#    #+#             */
/*   Updated: 2017/11/06 16:26:31 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_prtnarr_str(char **str, char sep)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		if (str[i + 1])
			ft_putchar(sep);
		i++;
	}
}
