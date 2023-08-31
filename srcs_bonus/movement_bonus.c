/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/27 13:47:16 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up(t_game *game)
{
	if (game->map[game->y - 1][game->x] != '1' && game->flag_exit == 0)
	{
		if (game->map[game->y - 1][game->x] == 'E')
			game->flag_exit = 1;
		else if (game->map[game->y - 1][game->x] == 'C')
			game->count_c += 1;
		game->y -= 1;
		game->map[game->y][game->x] = 'P';
		game->map[game->y + 1][game->x] = '0';
		game->dir = 'b';
		display_map(game);
		display_mov(game);
		if (game->count_c == game->count_c_max && game->flag_exit == 1)
			display_win(game, game->mlx, game->win);
	}
	else if (game->map[game->y - 1][game->x] != '1' && game->flag_exit == 1)
	{
		if (game->map[game->y - 1][game->x] == 'C')
			game->count_c++;
		which_flag_mov(game, 1);
		move_from_exit(game, game->y, game->x);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->y + 1][game->x] != '1' && game->flag_exit == 0)
	{
		if (game->map[game->y + 1][game->x] == 'C')
			game->count_c++;
		else if (game->map[game->y + 1][game->x] == 'E')
			game->flag_exit = 1;
		game->y += 1;
		game->map[game->y - 1][game->x] = '0';
		game->map[game->y][game->x] = 'P';
		game->dir = 'f';
		display_map(game);
		display_mov(game);
		if (game->count_c == game->count_c_max && game->flag_exit == 1)
			display_win(game, game->mlx, game->win);
	}
	else if (game->map[game->y + 1][game->x] != '1' && game->flag_exit == 1)
	{
		if (game->map[game->y + 1][game->x] == 'C')
			game->count_c++;
		which_flag_mov(game, 2);
		move_from_exit(game, game->y, game->x);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->y][game->x + 1] != '1' && game->flag_exit == 0)
	{
		if (game->map[game->y][game->x + 1] == 'E')
			game->flag_exit = 1;
		else if (game->map[game->y][game->x + 1] == 'C')
			game->count_c++;
		game->x += 1;
		game->map[game->y][game->x - 1] = '0';
		game->map[game->y][game->x] = 'P';
		game->dir = 'r';
		display_map(game);
		display_mov(game);
		if (game->count_c == game->count_c_max && game->flag_exit == 1)
			display_win(game, game->mlx, game->win);
	}
	else if (game->map[game->y][game->x + 1] != '1' && game->flag_exit == 1)
	{
		if (game->map[game->y][game->x + 1] == 'C')
			game->count_c++;
		which_flag_mov(game, 3);
		move_from_exit(game, game->y, game->x);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->y][game->x - 1] != '1' && game->flag_exit == 0)
	{
		if (game->map[game->y][game->x - 1] == 'C')
			game->count_c += 1;
		else if (game->map[game->y][game->x - 1] == 'E')
			game->flag_exit = 1;
		game->x -= 1;
		game->map[game->y][game->x + 1] = '0';
		game->map[game->y][game->x] = 'P';
		game->dir = 'l';
		display_map(game);
		display_mov(game);
		if (game->count_c == game->count_c_max && game->flag_exit == 1)
			display_win(game, game->mlx, game->win);
	}
	else if (game->map[game->y][game->x - 1] != '1' && game->flag_exit == 1)
	{
		if (game->map[game->y][game->x - 1] == 'C')
			game->count_c++;
		which_flag_mov(game, 4);
		move_from_exit(game, game->y, game->x);
	}
}
