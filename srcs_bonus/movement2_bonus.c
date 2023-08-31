/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/27 14:46:29 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	which_flag_mov(t_game *game, int dir)
{
	if (dir == 1)
	{
		game->flag_mov.y = -1;
		game->flag_mov.x = 0;
		game->dir = 'b';
	}
	else if (dir == 2)
	{
		game->flag_mov.y = 1;
		game->flag_mov.x = 0;
		game->dir = 'f';
	}
	else if (dir == 3)
	{
		game->flag_mov.y = 0;
		game->flag_mov.x = 1;
		game->dir = 'r';
	}
	else if (dir == 4)
	{
		game->flag_mov.y = 0;
		game->flag_mov.x = -1;
		game->dir = 'l';
	}
}

void	move_from_exit(t_game *game, int y, int x)
{
	game->y = game->y + game->flag_mov.y;
	game->x = game->x + game->flag_mov.x;
	if (game->map[game->y][game->x] == 'E')
		game->flag_exit = 1;
	else
		game->flag_exit = 0;
	game->map[game->y][game->x] = 'P';
	game->map[y][x] = 'E';
	display_map(game);
	display_mov(game);
}
