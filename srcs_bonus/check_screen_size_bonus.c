/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_screen_size_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/03/21 11:16:51 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_screen_size(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(game->mlx, &x, &y);
	if (x == 0 || y == 0)
		display_err_quit(1, game, "Function mlx get screen failed");
	if (x < IMG * game->w || y < IMG * game->h)
		display_err_quit(1, game, "Screen resolution too big");
}
