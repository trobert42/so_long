/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/08 17:02:43 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_to_exit(t_game	*game)
{
	int	x;
	int	y;

	if (game->count_c == game->count_c_max)
	{
		quit_game(game);
	}
}

void	update_image(t_game *game, int x, int y)
{


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
		game->map[y + 1][x] = game->map[y][x];
		game->map[y][x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->p, x * \
				IMG, y * IMG);
		mlx_put_image_to_window(game->mlx, game->win, game->b, x * \
				IMG, (y + 1) * IMG);
	}
	else if (game->map[y - 1][x] == 'E')
		if (game->count_c == game->count_c_max)
				move_to_exit(game);
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
		game->map[y - 1][x] = game->map[y][x];
		game->map[y][x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->p, x * \
				IMG, y * IMG);
		mlx_put_image_to_window(game->mlx, game->win, game->b, x * \
				IMG, (y - 1) * IMG);
	}
	else if (game->map[y + 1][x] == 'E')
			if (game->count_c == game->count_c_max)
				move_to_exit(game);
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
		game->map[y][x - 1] = game->map[y][x];
		game->map[y][x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->p, x * \
				IMG, y * IMG);
		mlx_put_image_to_window(game->mlx, game->win, game->b, (x - 1) * \
				IMG, y * IMG);
	}
	else if (game->map[y][x + 1] == 'E')
		if (game->count_c == game->count_c_max)
				move_to_exit(game);
}

void	move_left(t_game *game)
{
	int x;
	int y;

	y = game->y_player;
	x = game->x_player;
	if (game->map[y][x - 1] != '1')
	{

		if (game->map[y][x - 1] == 'C')
			game->count_c += 1;
		game->x_player -= 1;
		x -= 1; 
		game->map[y][x + 1] = '0';
		game->map[y][x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->p, x * \
				IMG, y * IMG);
		if (game->flag_exit == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->e, (x + 1) * \
				IMG, y * IMG);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->b, (x + 1) * \
				IMG, y * IMG);
		mlx_string_put(game->mlx,game->win, 0, IMG*(game->h_map + 1) , 0xFF99FF, "salut dan, on fait une aram?");
	}
	if (game->map[y][x - 1] == 'E' && game->count_c == game->count_c_max)
		move_to_exit(game);
	else if (game->map[y][x - 1] == 'E')
		game->flag_exit = 1;
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
	return (0);
}
