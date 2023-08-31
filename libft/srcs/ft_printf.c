/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:58:22 by zerudo            #+#    #+#             */
/*   Updated: 2022/02/21 15:33:22 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

int	check_flags(char c)
{
	char	*conversions;
	int		i;
	int		size_conv;
	int		flag;

	conversions = "cspdiuxX%";
	i = 0;
	flag = 0;
	size_conv = ft_strlen(conversions);
	while (i < size_conv)
	{
		if (conversions[i] == c)
			flag = 1;
		i++;
	}
	if (flag != 1)
		return (-1);
	return (1);
}

int	flags(va_list ap, char c, int len)
{
	if (c == 'c')
		len += print_c(ap);
	else if (c == 's')
		len += print_s(ap);
	else if (c == 'p')
		len += print_p(ap);
	else if (c == 'd' || c == 'i')
		len += print_d(ap);
	else if (c == 'u')
		len += print_u(ap);
	else if (c == 'x' || c == 'X')
		len += print_x(ap, c);
	else if (c == '%')
		len += print_purcent();
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s[i])
		return (-1);
	va_start(ap, s);
	while (s[i])
	{
		while (s[i] != '%' && s[i] != '\0')
		{
			ft_putchar(s[i++]);
			len++;
		}
		if (s[i] == '%' && s[i++] != '\0')
		{
			if (check_flags(s[i]) == 1)
				len = flags(ap, s[i++], len);
		}
	}
	va_end(ap);
	return (len);
}
