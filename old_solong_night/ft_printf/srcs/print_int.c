/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:16:38 by zerudo            #+#    #+#             */
/*   Updated: 2021/12/13 15:21:32 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen(int n)
{
	size_t			i;
	int				sign;
	unsigned int	nbr;

	i = 0;
	sign = 1;
	nbr = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nbr = -nbr;
		sign = -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	if (sign < 0)
		i++;
	return (i);
}

unsigned int	ft_abs(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	return (nb);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			sign;
	size_t			i;
	unsigned int	nbr;

	i = 0;
	sign = 0;
	str = malloc(sizeof(char) * ft_nbrlen(n) + 1);
	if (str == 0)
		return (NULL);
	if (n < 0)
		sign = 1;
	nbr = ft_abs(n);
	while (i < ft_nbrlen(n) - sign)
	{
		str[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == 1)
		str[i++] = '-';
	str[i] = '\0';
	ft_string_reverse(str);
	return (str);
}

size_t	print_d(va_list ap)
{
	char	*nbr;
	size_t	size;

	nbr = ft_itoa(va_arg(ap, int));
	size = ft_strlen(nbr);
	ft_putstr(nbr);
	free (nbr);
	return (size);
}
