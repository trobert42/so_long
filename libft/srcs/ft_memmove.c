/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:28:08 by zerudo            #+#    #+#             */
/*   Updated: 2022/02/21 15:32:34 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	int			i;
	char const	*ptr;
	char		*ptr2;

	ptr2 = dest;
	ptr = src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (0);
	if (src < dest)
	{
		while (++i <= n)
			ptr2[n - i] = ptr[n - i];
	}
	else
		while (n-- > 0)
			*(ptr2++) = *(ptr++);
	return (dest);
}
