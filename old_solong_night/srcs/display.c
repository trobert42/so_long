/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 13:01:27 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_day_player(t_game *game, void *win, int y, int x)
{
	if (game->dir == 'b')
		mlx_put_image_to_window(game->mlx, win, game->p_b, x * IMG, y * IMG);
	else if (game->dir == 'f')
		mlx_put_image_to_window(game->mlx, win, game->p_f, x * IMG, y * IMG);
	else if (game->dir == 'r')
		mlx_put_image_to_window(game->mlx, win, game->p_r, x * IMG, y * IMG);
	else if (game->dir == 'l')
		mlx_put_image_to_window(game->mlx, win, game->p_l, x * IMG, y * IMG);
}

void	display_day_map(t_game *game, void *mlx, void *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, game->wa, x * IMG, y * IMG);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, game->b, x * IMG, y * IMG);
			if (game->map[y][x] == 'P')
				display_day_player(game, game->win, y, x);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, game->c, x * IMG, y * IMG);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, game->e, x * IMG, y * IMG);
			x++;
		}
		y++;
	}
}

void	display_msg_error(t_game *game)
{
	printf("Error\n");
	printf("Problem in the Matrix\n");
	quit_game(game);
}

void	display_map(t_game *game)
{
	if (game->flag_night % 2 == 1)
		display_night_map(game, game->mlx, game->win);
	else if (game->flag_night % 2 == 0)
		display_day_map(game, game->mlx, game->win);
}
