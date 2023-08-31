/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:16:38 by zerudo            #+#    #+#             */
/*   Updated: 2022/02/21 15:37:52 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

int	print_d(va_list ap)
{
	char	*nbr;
	int		size;

	nbr = ft_itoa(va_arg(ap, int));
	size = ft_strlen(nbr);
	ft_putstr(nbr);
	free (nbr);
	return (size);
}
