/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:59:55 by zerudo            #+#    #+#             */
/*   Updated: 2022/02/21 15:34:03 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	index_start(char const *s1, const char *set)
{
	int	i;

	i = 0;
	if (is_set(s1[i], set) == 1 && s1[i])
	{
		while (is_set(s1[i], set) == 1 && s1[i])
			++i;
	}
	return (i);
}

static int	index_end(char const *s1, const char *set)
{
	int	count;

	count = ft_strlen(s1) - 1;
	if (is_set(s1[count], set) == 1 && count > 0)
	{
		while (is_set(s1[count], set) == 1 && count > 0)
			count--;
	}
	if (is_set(s1[count], set) == 1)
		count--;
	return (count);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*dest;

	if (!s1)
		return (NULL);
	if (index_start(s1, set) > index_end(s1, set))
		dest = ft_strdup("");
	else
		dest = ft_substr(s1, index_start(s1, set), index_end(s1, set) \
				- index_start(s1, set) + 1);
	return ((char *)dest);
}
