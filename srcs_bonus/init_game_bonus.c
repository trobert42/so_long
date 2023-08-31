/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/03/09 15:06:19 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_img(t_game *game, void *mlx, int img)
{
	game->tile.wa = mlx_xpm_file_to_image(mlx, "assets/w.xpm", &img, &img);
	if (game->tile.wa == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.c = mlx_xpm_file_to_image(mlx, "assets/c.xpm", &img, &img);
	if (game->tile.c == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.e = mlx_xpm_file_to_image(mlx, "assets/e.xpm", &img, &img);
	if (game->tile.e == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.b = mlx_xpm_file_to_image(mlx, "assets/b.xpm", &img, &img);
	if (game->tile.b == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.end = mlx_xpm_file_to_image(mlx, "assets/end.xpm", &img, &img);
	if (game->tile.end == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.start = mlx_xpm_file_to_image(mlx, "assets/start.xpm", \
			&img, &img);
	if (game->tile.start == NULL)
		display_err_quit(1, game, "Problem with init img");
}

void	init_img_player(t_game *game, void *mlx, int img)
{
	game->tile.p_f = mlx_xpm_file_to_image(mlx, "assets/p_f.xpm", &img, &img);
	if (game->tile.p_f == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.p_b = mlx_xpm_file_to_image(mlx, "assets/p_b.xpm", &img, &img);
	if (game->tile.p_b == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.p_l = mlx_xpm_file_to_image(mlx, "assets/p_l.xpm", &img, &img);
	if (game->tile.p_l == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.p_r = mlx_xpm_file_to_image(mlx, "assets/p_r.xpm", &img, &img);
	if (game->tile.p_r == NULL)
		display_err_quit(1, game, "Problem with init img");
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

void	init_img_void(t_game *game)
{
	game->tile.wa = NULL;
	game->tile.e = NULL;
	game->tile.c = NULL;
	game->tile.b = NULL;
	game->tile.p_f = NULL;
	game->tile.p_b = NULL;
	game->tile.p_l = NULL;
	game->tile.p_r = NULL;
	game->tile.start = NULL;
	game->tile.end = NULL;
	game->tile.s1 = NULL;
	game->tile.s2 = NULL;
	game->tile.s3 = NULL;
	game->tile.s4 = NULL;
	game->tile.s5 = NULL;
	game->dir = 'f';
}

void	init_game(t_game *game, int flag_reset)
{
	int	i;

	i = 0;
	game->flag_exit = 0;
	game->flag_end = 0;
	game->flag_start = 0;
	game->flag_anim = 0;
	game->flag_mov.x = 0;
	game->flag_mov.y = 0;
	game->count_c = 0;
	game->count_c_max = 0;
	game->count_step = 0;
	while (i < ft_strlen(game->str_map))
	{
		if (game->str_map[i++] == 'C')
			game->count_c_max++;
	}
	if (flag_reset == 0)
	{
		init_img_void(game);
		init_img(game, game->mlx, game->img);
		init_img_player(game, game->mlx, game->img);
		init_img_anim(game, game->mlx, game->img);
	}
	init_pos_player(game);
}
