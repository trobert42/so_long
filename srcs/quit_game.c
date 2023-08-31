/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/03/01 17:21:16 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_img(t_game *game)
{
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
	if (game->wa != NULL)
		mlx_destroy_image(game->mlx, game->wa);
	if (game->b != NULL)
		mlx_destroy_image(game->mlx, game->b);
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
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->str_map);
	free(game->mlx);
	close(game->fd);
	exit(0);
}
