/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:49:03 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 15:34:25 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

int	ft_nbrlen(int n)
{
	int				i;
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

void	ft_string_reverse(char *str)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i <= j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
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
	int				sign;
	int				i;
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
