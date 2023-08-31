/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:58:25 by trobert           #+#    #+#             */
/*   Updated: 2022/01/26 17:36:17 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *s, ...);
size_t			print_c(va_list ap);
size_t			print_s(va_list ap);
size_t			print_purcent(void);
size_t			print_d(va_list ap);
size_t			print_p(va_list ap);
size_t			print_u(va_list ap);
size_t			print_x(va_list ap, char c);
size_t			ft_strlen(char *s);
void			ft_putchar(char c);
void			ft_string_reverse(char *str);
void			ft_putstr(char *str);
void			ft_strtoupper(char *str);
unsigned int	ft_abs(int n);
char			*ft_itoa(int n);
size_t			ft_nbrlen(int n);
size_t			ft_u_nbrlen(unsigned long long n, int base);
char			*ft_uitoa_base(unsigned long long nbr, int base);

#endif
