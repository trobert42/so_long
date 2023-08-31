/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:43:39 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 15:34:48 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!(*alst))
		*alst = new;
	else
	{
		temp = *alst;
		*alst = ft_lstlast(*alst);
		(*alst)->next = new;
		*alst = temp;
	}
}
