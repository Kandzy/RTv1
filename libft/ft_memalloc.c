/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:47:11 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 12:49:26 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*buff;

	buff = (char*)malloc(size);
	if (buff == NULL)
		return (NULL);
	ft_memset(buff, 0, size);
	return (buff);
}
