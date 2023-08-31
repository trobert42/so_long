/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/03/11 14:00:37 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_game *game, void *mlx, int img)
{
	game->wa = mlx_xpm_file_to_image(mlx, "assets/w.xpm", &img, &img);
	if (game->wa == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->c = mlx_xpm_file_to_image(mlx, "assets/c.xpm", &img, &img);
	if (game->c == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->e = mlx_xpm_file_to_image(mlx, "assets/e.xpm", &img, &img);
	if (game->e == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->b = mlx_xpm_file_to_image(mlx, "assets/b.xpm", &img, &img);
	if (game->b == NULL)
		display_err_quit(1, game, "Problem with init img");
}

void	init_img_player(t_game *game, void *mlx, int img)
{
	game->p_f = mlx_xpm_file_to_image(mlx, "assets/p_f.xpm", &img, &img);
	if (game->p_f == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->p_b = mlx_xpm_file_to_image(mlx, "assets/p_b.xpm", &img, &img);
	if (game->p_b == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->p_l = mlx_xpm_file_to_image(mlx, "assets/p_l.xpm", &img, &img);
	if (game->p_l == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->p_r = mlx_xpm_file_to_image(mlx, "assets/p_r.xpm", &img, &img);
	if (game->p_r == NULL)
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
	game->wa = NULL;
	game->c = NULL;
	game->e = NULL;
	game->b = NULL;
	game->p_f = NULL;
	game->p_b = NULL;
	game->p_l = NULL;
	game->p_r = NULL;
}

void	init_game(t_game *game)
{
	int	i;

	i = 0;
	game->count_c = 0;
	game->count_c_max = 0;
	game->count_step = 0;
	game->flag_mov.x = 0;
	game->flag_mov.y = 0;
	game->flag_exit = 0;
	game->dir = 'f';
	while (i < ft_strlen(game->str_map))
	{
		if (game->str_map[i++] == 'C')
			game->count_c_max++;
	}
	init_img_void(game);
	init_img(game, game->mlx, game->img);
	init_img_player(game, game->mlx, game->img);
	init_pos_player(game);
}
