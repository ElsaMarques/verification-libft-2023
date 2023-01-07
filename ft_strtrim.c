/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-oliv <ede-oliv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:27:21 by ede-oliv          #+#    #+#             */
/*   Updated: 2023/01/07 04:38:36 by ede-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	set_includes_char(char const *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static size_t	index_start(char const *s1, char const *set)
{
	size_t	res;

	res = 0;
	while (s1[res] && set_includes_char(set, s1[res]))
		res++;
	return (res);
}

static size_t	index_end(char const *s1, char const *set)
{
	size_t	res;

	res = ft_strlen(s1);
	if (!res)
		return (0);
	else
		res--;
	while (res && set_includes_char(set, s1[res]))
		res--;
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_i;
	size_t	end_i;
	size_t	res_len;

	if (!s1 || !set)
		return (NULL);
	start_i = index_start(s1, set);
	end_i = index_end(s1, set);
	if (start_i >= end_i)
		res_len = end_i - start_i;
	else
		res_len = 0;
	return (ft_substr(s1, start_i, end_i - start_i + 1));
}
