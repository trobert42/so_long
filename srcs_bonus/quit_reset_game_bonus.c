/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_reset_game_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/23 16:15:26 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	reset_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->h)
		free(game->map[i++]);
	free(game->map);
	game->map = ft_split(game->str_map, '\n');
	init_game(game, 1);
	display_map(game);
	game->flag_start = 1;
}

void	destroy_img(t_game *game)
{
	if (game->tile.p_f != NULL)
		mlx_destroy_image(game->mlx, game->tile.p_f);
	if (game->tile.p_b != NULL)
		mlx_destroy_image(game->mlx, game->tile.p_b);
	if (game->tile.p_r != NULL)
		mlx_destroy_image(game->mlx, game->tile.p_r);
	if (game->tile.p_l != NULL)
		mlx_destroy_image(game->mlx, game->tile.p_l);
	if (game->tile.e != NULL)
		mlx_destroy_image(game->mlx, game->tile.e);
	if (game->tile.c != NULL)
		mlx_destroy_image(game->mlx, game->tile.c);
	if (game->tile.wa != NULL)
		mlx_destroy_image(game->mlx, game->tile.wa);
	if (game->tile.b != NULL)
		mlx_destroy_image(game->mlx, game->tile.b);
	if (game->tile.end != NULL)
		mlx_destroy_image(game->mlx, game->tile.end);
	if (game->tile.start != NULL)
		mlx_destroy_image(game->mlx, game->tile.start);
}

void	destroy_img_anim(t_game *game)
{
	if (game->tile.s1 != NULL)
		mlx_destroy_image(game->mlx, game->tile.s1);
	if (game->tile.s2 != NULL)
		mlx_destroy_image(game->mlx, game->tile.s2);
	if (game->tile.s3 != NULL)
		mlx_destroy_image(game->mlx, game->tile.s3);
	if (game->tile.s4 != NULL)
		mlx_destroy_image(game->mlx, game->tile.s4);
	if (game->tile.s5 != NULL)
		mlx_destroy_image(game->mlx, game->tile.s5);
}

int	quit_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->h)
		free(game->map[i++]);
	free(game->map);
	mlx_loop_end(game->mlx);
	destroy_img(game);
	destroy_img_anim(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->str_map);
	free(game->mlx);
	close(game->fd);
	exit(0);
}
