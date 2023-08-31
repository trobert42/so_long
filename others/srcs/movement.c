/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 12:24:18 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_from_exit(t_game *game, int y, int x)
{
	game->map[y][x] = 'E';
	display_map(game);
	display_mov(game);
	game->flag_exit = 0;
}

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
		game->y -= 1;
		game->map[game->y][game->x] = 'P';
		move_from_exit(game, game->y + 1, game->x);
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
		game->y += 1;
		game->map[game->y][game->x] = 'P';
		move_from_exit(game, game->y - 1, game->x);
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
		game->x += 1;
		game->map[game->y][game->x] = 'P';
		move_from_exit(game, game->y, game->x - 1);
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
		game->x -= 1;
		game->map[game->y][game->x] = 'P';
		move_from_exit(game, game->y, game->x + 1);
	}
}
