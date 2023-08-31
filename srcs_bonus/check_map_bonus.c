/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:03:50 by trobert           #+#    #+#             */
/*   Updated: 2022/03/18 20:05:56 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	check_h(char **tabtab)
{
	int	i;
	int	size;
	int	size_previous;

	i = 1;
	size = 0;
	size_previous = 0;
	while (tabtab[i] != 0)
	{
		size = ft_strlen(tabtab[i]);
		size_previous = ft_strlen(tabtab[i - 1]);
		if (size != size_previous)
			return (-1);
		i++;
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
				!= 'P' && game.str_map[i] != 'C' \
				&& game.str_map[i] != '\n')
			return (-1);
		if (game.str_map[i] == '\n' && game.str_map[i + 1] == '\n')
			return (-1);
		i++;
	}
	if (game.str_map[i - 1] == '\n')
		return (-1);
	if (count_char(game.str_map, 'P') != 1)
		return (-1);
	if (count_char(game.str_map, 'C') < 1)
		return (-1);
	if (count_char(game.str_map, 'E') < 1)
		return (-1);
	return (1);
}
