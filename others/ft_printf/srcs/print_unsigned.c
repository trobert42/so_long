/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:27:04 by zerudo            #+#    #+#             */
/*   Updated: 2021/12/13 16:50:54 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_u_nbrlen(unsigned long long n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n /= (unsigned int) base;
	}
	return (len);
}

char	*ft_uitoa_base(unsigned long long nbr, int base)
{
	char	*str;
	char	*basesystem;
	size_t	i;
	size_t	size;

	i = 0;
	basesystem = "0123456789abcdef";
	size = ft_u_nbrlen(nbr, base);
	str = malloc(sizeof(char) * size + 1);
	if (str == 0)
		return (NULL);
	while (i < size && nbr >= (unsigned long long) base)
	{
		str[i++] = basesystem[nbr % base];
		nbr /= base;
	}
	str[i++] = basesystem[nbr % base];
	str[i] = '\0';
	ft_string_reverse(str);
	return (str);
}

size_t	print_u(va_list ap)
{
	char	*nbr;
	size_t	size;

	nbr = ft_uitoa_base(va_arg(ap, unsigned int), 10);
	size = ft_strlen(nbr);
	ft_putstr(nbr);
	free (nbr);
	return (size);
}

size_t	print_x(va_list ap, char c)
{
	char	*nbr;
	size_t	size;

	nbr = ft_uitoa_base(va_arg(ap, unsigned int), 16);
	size = ft_strlen(nbr);
	if (c == 'x')
	{
		ft_putstr(nbr);
		free(nbr);
	}
	else
	{
		ft_strtoupper(nbr);
		ft_putstr(nbr);
		free(nbr);
	}
	return (size);
}
