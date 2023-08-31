/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:36:31 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 15:38:32 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*yoshi;

	yoshi = malloc(sizeof(t_list));
	if (!yoshi)
		return (NULL);
	yoshi->content = content;
	yoshi->next = NULL;
	return (yoshi);
}
