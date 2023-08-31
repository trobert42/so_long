/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/07 09:25:27 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_to_exit(t_game	*game, int y, int x)
{
	game->map[y][x] = '0';
	display_map(game);
	if (game->count_c == game->count_c_max)
	{
		mlx_string_put(game->mlx,game->win, 0, IMG*(game->h_map + 1) , 0xFF99FF, "FINI");
	}
	else
	{
	}
}

void	move_up(t_game *game)
{
	int x;
	int y;

	y = game->y_player;
	x = game->x_player;
	if (game->map[y - 1][x] != '1' && game->map[y - 1][x] != 'E')
	{

		if (game->map[y - 1][x] == 'C')
			game->count_c += 1;
		game->y_player -= 1;
		y -= 1; 
		game->map[y + 1][x] = '0';
		game->map[y][x] = 'P';
		display_map(game);
	}
	else if (game->map[y - 1][x] == 'E')
	{

		game->map[y - 1][x] = 'P';
		game->y_player -= 1;
		move_to_exit(game, y, x);
	}
}

void	move_down(t_game *game)
{
	int x;
	int y;

	y = game->y_player;
	x = game->x_player;
	if (game->map[y + 1][x] != '1' && game->map[y + 1][x] != 'E')
	{

		if (game->map[y + 1][x] == 'C')
			game->count_c += 1;
		game->y_player += 1;
		y += 1; 
		game->map[y - 1][x] = '0';
		game->map[y][x] = 'P';
		display_map(game);
	}
	else if (game->map[y + 1][x] == 'E')
	{
		game->map[y + 1][x] = 'P';
		game->y_player += 1;
		move_to_exit(game, y, x);
	}
}

void	move_right(t_game *game)
{
	int x;
	int y;

	y = game->y_player;
	x = game->x_player;
	if (game->map[y][x + 1] != '1' && game->map[y][x + 1] != 'E')
	{

		if (game->map[y][x + 1] == 'C')
			game->count_c += 1;
		game->x_player += 1;
		x += 1; 
		game->map[y][x - 1] = '0';
		game->map[y][x] = 'P';
		display_map(game);
	}
	else if (game->map[y][x + 1] == 'E')
	{
		game->map[y][x + 1] = 'P';
		game->x_player += 1;
		move_to_exit(game, y, x);
	}
}

void	move_left(t_game *game)
{
	int x;
	int y;

	y = game->y_player;
	x = game->x_player;
	if (game->map[y][x - 1] != '1' && game->map[y][x - 1] != 'E')
	{

		if (game->map[y][x - 1] == 'C')
			game->count_c += 1;
		game->x_player -= 1;
		x -= 1;
		game->map[y][x + 1] = '0';
		game->map[y][x] = 'P';
		display_map(game);
	}
	else if (game->map[y][x - 1] == 'E')
	{
		game->map[y][x - 1] = 'P';
		game->x_player -= 1;
		move_to_exit(game, y, x);
	}// quand je fais gauche sur leviator et puis droite, leviator disparait
}



int	input(int keysym, t_game *game)
{
	if (keysym == 99)
	{
		mlx_destroy_window(game->mlx, game->win);
		quit_game(game);
		return (0);
	}
	else if (keysym == 122)
		move_up(game);
	else if (keysym == 115)
		move_down(game);
	else if (keysym == 100)
		move_right(game);
	else if (keysym == 113)
		move_left(game);
	else if (keysym == 114)
	{
		
	}
	return (0);
}
