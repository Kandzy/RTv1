/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:33:40 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 13:33:41 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*strbuff;

	strbuff = (char*)malloc(sizeof(char) * size + 1);
	if (strbuff == NULL)
		return (NULL);
	ft_memset(strbuff, '\0', size + 1);
	return (strbuff);
}
