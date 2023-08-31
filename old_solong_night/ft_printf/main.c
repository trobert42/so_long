/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:13:28 by zerudo            #+#    #+#             */
/*   Updated: 2022/01/27 11:00:22 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int ft_printf(const char *s, ...);

int	main()
{

	int a = 45;
	int b = -432;
	int c = 0;
	unsigned int d = 2342343;
	unsigned int e = 42; // 2A
	unsigned int f = -123;
	char C = 'c';
	char *str = NULL;
	int *ptr = 0;
	char str2[] = "MAMMA MIA";


	ft_printf("1 -> my printf");
	ft_printf("\n");
	ft_printf("2 -> real printf2");
	ft_printf("\n ------------------beginning--------\n"); 

	ft_printf("%");
	ft_printf("\n");
//	printf(" count2 = %d", printf("%"));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en p : %p,", ptr));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en p : %p,", ptr));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en s : %s,", str));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en s : %s,", str));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en d : %d,", a));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en d : %d,", a));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en d : %d,", b));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en d : %d,", b));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en d : %d,", c));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en d : %d,", c));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en u : %u,", d));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en u : %u,", d));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en c : %c,", C));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en c : %c,", C));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en s : %s,", str));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en s : %s,", str));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en s "" : %s,", str2));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en s "" : %s,", str2));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en x : %x,", e));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en x : %x,", e));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en x : %x,", d));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en x : %x,", d));
	printf("\n ---------------------------------------------------\n");


	ft_printf(" count = %d", ft_printf("1 en X : %X,", d));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en X : %X,", d));
	printf("\n ---------------------------------------------------\n");

	ft_printf(" count = %d", ft_printf("1 en x negative : %x,", f));
	ft_printf("\n");
	printf(" count2 = %d", printf("2 en x negative : %x,", f));
	printf("\n ---------------------------------------------------\n");

	return (0);
}
