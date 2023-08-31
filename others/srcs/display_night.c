/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_night.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/14 11:36:19 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_night_player(t_game *game, void *mlx, void *win, int y, int x)
{
	if (game->dir == 'b')
		mlx_put_image_to_window(mlx, win, game->p_b_n, x * IMG, y * IMG);
	else if (game->dir == 'f')
		mlx_put_image_to_window(mlx, win, game->p_f_n, x * IMG, y * IMG);
	else if (game->dir == 'r')
		mlx_put_image_to_window(mlx, win, game->p_r_n, x * IMG, y * IMG);
	else if (game->dir == 'l')
		mlx_put_image_to_window(mlx, win, game->p_l_n, x * IMG, y * IMG);
}

void	display_night_map(t_game *game, void *mlx, void *win)
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
				mlx_put_image_to_window(mlx, win, game->wa_n, x * IMG, y * IMG);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, game->b_n, x * IMG, y * IMG);
			if (game->map[y][x] == 'P')
				display_night_player(game, mlx, game->win, y, x);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, game->c_n, x * IMG, y * IMG);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, game->e_n, x * IMG, y * IMG);
			x++;
		}
		y++;
	}
}


void	init_night_img(t_game *game, void *mlx)
{

	game->wa_n = mlx_xpm_file_to_image(mlx, "w_n.xpm", &game->img, &game->img);
	if (game->wa_n == NULL)
		quit_game(game);
	game->c_n = mlx_xpm_file_to_image(mlx, "c_n.xpm", &game->img, &game->img);
	if (game->c_n == NULL)
		quit_game(game);
	game->e_n = mlx_xpm_file_to_image(mlx, "e_n.xpm", &game->img, &game->img);
	if (game->e_n == NULL)
		quit_game(game);
	game->b_n = mlx_xpm_file_to_image(mlx, "b_n.xpm", &game->img, &game->img);
	if (game->b_n == NULL)
		quit_game(game);
}

void	init_night_img_player(t_game *game, void *mlx)
{
	game->p_f_n = mlx_xpm_file_to_image(mlx, "p_f_n.xpm", &game->img, &game->img);
	if (game->p_f_n == NULL)
		quit_game(game);

	game->p_b_n = mlx_xpm_file_to_image(mlx, "p_b_n.xpm", &game->img, &game->img);
	if (game->p_b_n == NULL)
		quit_game(game);

	game->p_l_n = mlx_xpm_file_to_image(mlx, "p_l_n.xpm", &game->img, &game->img);
	if (game->p_l_n == NULL)
		quit_game(game);

	game->p_r_n = mlx_xpm_file_to_image(mlx, "p_r_n.xpm", &game->img, &game->img);
	if (game->p_r_n == NULL)
		quit_game(game);
}

void	night_mode(t_game *game)
{
	if (game->flag_night % 2 == 1) //if its odd
		display_day_map(game, game->mlx, game->win);
	else
		display_night_map(game, game->mlx, game->win);
	game->flag_night++;
}
