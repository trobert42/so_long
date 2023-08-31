/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/03/14 14:21:01 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_img_anim(t_game *game, void *mlx, int img)
{
	game->tile.s1 = mlx_xpm_file_to_image(mlx, "assets/s1.xpm", &img, &img);
	if (game->tile.s1 == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.s2 = mlx_xpm_file_to_image(mlx, "assets/s2.xpm", &img, &img);
	if (game->tile.s2 == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.s3 = mlx_xpm_file_to_image(mlx, "assets/s3.xpm", &img, &img);
	if (game->tile.s3 == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.s4 = mlx_xpm_file_to_image(mlx, "assets/s4.xpm", &img, &img);
	if (game->tile.s4 == NULL)
		display_err_quit(1, game, "Problem with init img");
	game->tile.s5 = mlx_xpm_file_to_image(mlx, "assets/s5.xpm", &img, &img);
	if (game->tile.s5 == NULL)
		display_err_quit(1, game, "Problem with init img");
}

int	anim_frame(t_game *game)
{
	int	i;

	i = game->i_anim;
	if (game->flag_anim == 1 && game->flag_end == 0)
	{
		if (i == 120000)
			mlx_put_image_to_window(game->mlx, game->win, game->tile.s2, \
					game->x * IMG, game->y * IMG);
		if (i == 132000)
			mlx_put_image_to_window(game->mlx, game->win, game->tile.s3, \
					game->x * IMG, game->y * IMG);
		if (i == 144000)
			mlx_put_image_to_window(game->mlx, game->win, game->tile.s4, \
					game->x * IMG, game->y * IMG);
		if (i == 156000)
			mlx_put_image_to_window(game->mlx, game->win, game->tile.s5, \
					game->x * IMG, game->y * IMG);
		if (i > 156001)
			i = 108000;
	}
	game->i_anim = ++i;
	return (0);
}
