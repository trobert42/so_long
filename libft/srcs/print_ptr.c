/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:12:36 by zerudo            #+#    #+#             */
/*   Updated: 2022/02/21 15:38:09 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

int	print_p(va_list ap)
{
	char				*ptr;
	unsigned long long	*adress;
	int					size;

	adress = va_arg(ap, void *);
	ptr = ft_uitoa_base((unsigned long long)adress, 16);
	size = ft_strlen(ptr);
	if (adress == NULL)
	{
		ft_putstr("0x0");
		free(ptr);
		return (3);
	}
	else
	{
		ft_putstr("0x");
		size += 2;
		ft_putstr(ptr);
		free(ptr);
	}
	return (size);
}
