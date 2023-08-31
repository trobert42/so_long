/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 12:29:40 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	init_img(t_game *game, void *mlx, int img)
{
	game->wa = mlx_xpm_file_to_image(mlx, "assets/w.xpm", &img, &img);
	if (game->wa == NULL)
		display_msg_error(game);
	game->c = mlx_xpm_file_to_image(mlx, "assets/c.xpm", &img, &img);
	if (game->c == NULL)
		display_msg_error(game);
	game->e = mlx_xpm_file_to_image(mlx, "assets/e.xpm", &img, &img);
	if (game->e == NULL)
		display_msg_error(game);
	game->b = mlx_xpm_file_to_image(mlx, "assets/b.xpm", &img, &img);
	if (game->b == NULL)
		display_msg_error(game);
	game->end = mlx_xpm_file_to_image(mlx, "assets/end.xpm", &img, &img);
	if (game->end == NULL)
		display_msg_error(game);
	game->start = mlx_xpm_file_to_image(mlx, "assets/start.xpm", &img, &img);
	if (game->start == NULL)
		display_msg_error(game);
}

void	init_img_player(t_game *game, void *mlx, int img)
{
	game->p_f = mlx_xpm_file_to_image(mlx, "assets/p_f.xpm", &img, &img);
	if (game->p_f == NULL)
		display_msg_error(game);
	game->p_b = mlx_xpm_file_to_image(mlx, "assets/p_b.xpm", &img, &img);
	if (game->p_b == NULL)
		display_msg_error(game);
	game->p_l = mlx_xpm_file_to_image(mlx, "assets/p_l.xpm", &img, &img);
	if (game->p_l == NULL)
		display_msg_error(game);
	game->p_r = mlx_xpm_file_to_image(mlx, "assets/p_r.xpm", &img, &img);
	if (game->p_r == NULL)
		display_msg_error(game);
}

void	init_pos_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == 'P')
			{
				game->x = x;
				game->y = y;
			}
			x++;
		}
		y++;
	}
}

void	init_game(t_game *game, int flag_reset)
{
	int	i;

	i = 0;
	game->flag_exit = 0;
	game->flag_end = 0;
	game->flag_start = 0;
	game->flag_night = 0;
	game->count_c = 0;
	game->count_c_max = 0;
	game->count_step = 0;
	game->dir = 'f';
	while (i < ft_strlen(game->str_map))
	{
		if (game->str_map[i++] == 'C')
			game->count_c_max++;
	}
	if (flag_reset == 0)
	{
		init_img(game, game->mlx, game->img);
		init_img_player(game, game->mlx, game->img);
		init_night_img(game, game->mlx);
		init_night_img_player(game, game->mlx);
	}
	init_pos_player(game);
}
