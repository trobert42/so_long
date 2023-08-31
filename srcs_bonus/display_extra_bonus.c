/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_extra_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/03/09 12:27:13 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	display_mov(t_game *game)
{
	char	*nbr;

	game->count_step++;
	ft_printf("Number of steps : %d \n", game->count_step);
	mlx_string_put(game->mlx, game->win, 20, (IMG * game->h) - 10, \
			0XFF99FF, "Moves :");
	mlx_string_put(game->mlx, game->win, 21, (IMG * game->h) - 10, \
			0XFF99FF, "Moves :");
	nbr = ft_itoa(game->count_step);
	mlx_string_put(game->mlx, game->win, 80, (IMG * game->h) - 10, \
			0XFF99FF, nbr);
	mlx_string_put(game->mlx, game->win, 81, (IMG * game->h) - 10, \
			0XFF99FF, nbr);
	free(nbr);
}

void	display_win(t_game *game, void *mlx, void *win)
{
	int	pos_x;
	int	pos_y;

	pos_x = (IMG * game->w) / 2 - 300;
	pos_y = (IMG * game->h) / 2 - 170;
	game->flag_end = 1;
	mlx_put_image_to_window(mlx, win, game->tile.end, pos_x, pos_y);
	mlx_hook(game->win, 2, 1L >> 0, input, game);
}

void	display_start(t_game *game, void *mlx, void *win)
{
	int	pos_x;
	int	pos_y;

	pos_x = (IMG * game->w) / 2 - 350;
	pos_y = (IMG * game->h) / 2 - (438 / 2);
	mlx_put_image_to_window(mlx, win, game->tile.start, pos_x, pos_y);
}
