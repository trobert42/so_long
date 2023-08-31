/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_reset_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 11:59:13 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (game->wa != NULL)
		mlx_destroy_image(game->mlx, game->wa);
	if (game->p_f != NULL)
		mlx_destroy_image(game->mlx, game->p_f);
	if (game->p_b != NULL)
		mlx_destroy_image(game->mlx, game->p_b);
	if (game->p_r != NULL)
		mlx_destroy_image(game->mlx, game->p_r);
	if (game->p_l != NULL)
		mlx_destroy_image(game->mlx, game->p_l);
	if (game->e != NULL)
		mlx_destroy_image(game->mlx, game->e);
	if (game->c != NULL)
		mlx_destroy_image(game->mlx, game->c);
	if (game->b != NULL)
		mlx_destroy_image(game->mlx, game->b);
	if (game->end != NULL)
		mlx_destroy_image(game->mlx, game->end);
	if (game->start != NULL)
		mlx_destroy_image(game->mlx, game->start);
}

void	destroy_night_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wa_n);
	mlx_destroy_image(game->mlx, game->p_f_n);
	mlx_destroy_image(game->mlx, game->p_b_n);
	mlx_destroy_image(game->mlx, game->p_r_n);
	mlx_destroy_image(game->mlx, game->p_l_n);
	mlx_destroy_image(game->mlx, game->e_n);
	mlx_destroy_image(game->mlx, game->c_n);
	mlx_destroy_image(game->mlx, game->b_n);
}

int	quit_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->h)
		free(game->map[i++]);
	free(game->map);
	mlx_loop_end(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->str_map);
	free(game->mlx);
	close(game->fd);
	exit(0);
}
