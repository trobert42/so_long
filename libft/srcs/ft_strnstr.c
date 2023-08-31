/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:31:44 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 15:33:34 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

char	*ft_strnstr(const char *str, const char *to_find, int n)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] && i < n && i < ft_strlen(str))
	{
		j = 0;
		start = i;
		while (str[i] == to_find[j] && str[i] != '\0' && i < n)
		{
			i++;
			j++;
		}
		i = start;
		if (to_find[j] == '\0')
			return ((char *)str + start);
		++i;
	}
	return (0);
}
