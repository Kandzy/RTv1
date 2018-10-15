/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:06:42 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/30 10:06:45 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_num_of_str(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] != '\0')
		n = 1;
	else
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n++;
	}
	return (n);
}

static char		*ft_new_string(char const *str, char c, int *j)
{
	char	*newstr;
	int		k;
	int		n;
	int		i;

	n = 0;
	i = *j;
	while (str[i] == c)
		i++;
	n = 0;
	while (str[i + n] != c && str[i + n] != '\0')
		n++;
	newstr = ft_strnew(n);
	k = 0;
	while (str[i] != c)
	{
		newstr[k] = str[i];
		k++;
		i++;
		if (str[i] == '\0')
			break ;
	}
	*j = i;
	return (newstr);
}

static void		ft_clear(char **str, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		str[j] = NULL;
		j++;
	}
	ft_memdel((void**)str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**outstr;
	int		n;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	n = ft_num_of_str(s, c);
	if (!(outstr = (char**)ft_memalloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		outstr[i] = ft_new_string(s, c, &j);
		if (outstr[i] == NULL)
		{
			ft_clear(outstr, i);
			return (NULL);
		}
		i++;
	}
	outstr[i] = NULL;
	return (outstr);
}
