/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:28:08 by zerudo            #+#    #+#             */
/*   Updated: 2022/02/21 15:31:42 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int					i;
	const unsigned char	*ptr;
	const unsigned char	*ptr2;

	ptr = s1;
	ptr2 = s2;
	i = 0;
	if (n > 0)
	{
		while ((ptr[i] == ptr2[i]) && i < n - 1)
			i++;
		return (ptr[i] - ptr2[i]);
	}
	return (0);
}
