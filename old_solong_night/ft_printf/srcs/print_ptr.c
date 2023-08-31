/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:12:36 by zerudo            #+#    #+#             */
/*   Updated: 2022/01/26 15:07:07 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_p(va_list ap)
{
	char				*ptr;
	unsigned long long	*adress;
	size_t				size;

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
