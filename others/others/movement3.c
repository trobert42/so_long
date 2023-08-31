/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/07 11:28:35 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_to_exit(t_game	*game, int y, int x)
{

	if (game->count_c == game->count_c_max)
	{
		mlx_string_put(game->mlx,game->win, 0, IMG*(game->h_map + 1) , 0xFF99FF, "FINI");
	}
	else
	{
		game->map[y][x] = 'E';
		display_map(game);
		game->flag_exit = 0;
	}
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
		game->map[game->y + 1][game->x] = '0';
		game->map[game->y][game->x] = 'P';
		display_map(game);
	}
	else if (game->map[game->y - 1][game->x] != '1' && game->flag_exit == 1)
	{
		game->y -= 1;
		game->map[game->y][game->x] = 'P';
		move_to_exit(game, game->y + 1, game->x);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->y + 1][game->x] != '1' && game->flag_exit == 0)
	{

		if (game->map[game->y + 1][game->x] == 'C')
			game->count_c += 1;
		else if (game->map[game->y + 1][game->x] == 'E')
			game->flag_exit = 1;
		game->y += 1; 
		game->map[game->y - 1][game->x] = '0';
		game->map[game->y][game->x] = 'P';
		display_map(game);
	}
	else if (game->map[game->y + 1][game->x] != '1' && game->flag_exit == 1)
	{
		game->y += 1;
		game->map[game->y][game->x] = 'P';
		move_to_exit(game, game->y - 1, game->x);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->y][game->x + 1] != '1' && game->flag_exit == 0)
	{

		if (game->map[game->y][game->x + 1] == 'E')
			game->flag_exit = 1;
		else if (game->map[game->y][game->x + 1] == 'C')
			game->count_c += 1;
		game->x += 1;
		game->map[game->y][game->x - 1] = '0';
		game->map[game->y][game->x] = 'P';
		display_map(game);
	}
	else if (game->map[game->y][game->x + 1] != '1' && game->flag_exit == 1)
	{
		game->x += 1;
		game->map[game->y][game->x] = 'P';
		move_to_exit(game, game->y, game->x - 1);
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
		display_map(game);
	}
	else if (game->map[game->y][game->x - 1] != '1' && game->flag_exit == 1)
	{
		game->x -= 1;
		game->map[game->y][game->x] = 'P';
		move_to_exit(game, game->y, game->x + 1);
	}
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
	else if (keysym == 114) //reset
	{
		
	}
	return (0);
}
