/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:38:26 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 14:38:28 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		len;
	int		count;

	if (!s)
		return ;
	count = 0;
	len = ft_strlen(s);
	while (count < len)
	{
		s[count] = '\0';
		count++;
	}
}
