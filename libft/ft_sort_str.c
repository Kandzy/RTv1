/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:39:02 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/24 14:39:05 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_str(int n, char **str_arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_strcmp(str_arr[i], str_arr[j]) > 0)
			{
				temp = str_arr[i];
				str_arr[i] = str_arr[j];
				str_arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}
