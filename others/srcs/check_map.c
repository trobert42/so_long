/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:03:50 by trobert           #+#    #+#             */
/*   Updated: 2022/02/28 16:36:00 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_h(char *str)
{
	int	i;
	int	count_w;
	int	count_w_previous;

	i = 0;
	count_w_previous = 0;
	while (i < ft_strlen(str))
	{
		count_w = 0;
		while (i < ft_strlen(str))
		{
			if (str[i++] == '\n')
				count_w++;
		}
		if (count_w_previous != 0)
			if (count_w != count_w_previous)
				return (-1);
		count_w_previous = count_w;
	}
	return (1);
}

int	check_fence(t_game game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < game.h)
	{
		if (game.map[i][0] != '1' || game.map[i][game.w - 1] != '1')
			return (-1);
		i++;
	}
	while (y < game.w)
	{
		if (game.map[0][y] != '1' || game.map[game.h - 1][y] != '1')
			return (-1);
		y++;
	}
	return (1);
}

int	count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < ft_strlen(str))
	{
		if (str[i++] == c)
			count++;
	}
	return (count);
}

int	check_char(t_game game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game.str_map))
	{
		if (game.str_map[i] != '1' && game.str_map[i] != '0' \
				&& game.str_map[i] != 'E' && game.str_map[i] \
				!= 'P' && game.str_map[i] != 'C')
		{
			if (i % game.h == 0 && game.str_map[i] != '\n')
				return (-1);
		}
		i++;
	}
	if (count_char(game.str_map, 'P') != 1)
		return (-1);
	if (count_char(game.str_map, 'C') < 1)
		return (-1);
	if (count_char(game.str_map, 'E') < 1)
		return (-1);
	return (1);
}
