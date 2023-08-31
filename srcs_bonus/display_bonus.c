/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/03/09 14:58:10 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	display_map2(t_game *game, void *imgtile, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, imgtile, x * IMG, y * IMG);
}

void	display_player(t_game *game, int y, int x)
{
	if (game->dir == 'b')
		display_map2(game, game->tile.p_b, x, y);
	else if (game->dir == 'f')
		display_map2(game, game->tile.p_f, x, y);
	else if (game->dir == 'r')
		display_map2(game, game->tile.p_r, x, y);
	else if (game->dir == 'l')
		display_map2(game, game->tile.p_l, x, y);
}

void	display_map(t_game *game)
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
				display_map2(game, game->tile.wa, x, y);
			if (game->map[y][x] == '0')
				display_map2(game, game->tile.b, x, y);
			if (game->map[y][x] == 'P')
				display_player(game, y, x);
			if (game->map[y][x] == 'C')
				display_map2(game, game->tile.c, x, y);
			if (game->map[y][x] == 'E')
				display_map2(game, game->tile.e, x, y);
			x++;
		}
		y++;
	}
}

void	display_err_quit(int flag, t_game *game, char *str)
{
	int	i;

	i = 0;
	ft_printf("Error\n");
	ft_printf("%s \n", str);
	if (flag == 1)
		quit_game(game);
	else if (flag == 2)
	{
		while (i < game->h)
			free(game->map[i++]);
		free(game->map);
		free(game->str_map);
		exit(0);
	}
	else
		exit(0);
}
