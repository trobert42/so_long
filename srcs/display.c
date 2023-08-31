/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/03/11 14:31:59 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_player(t_game *game, void *win, int y, int x)
{
	if (game->dir == 'b')
		mlx_put_image_to_window(game->mlx, win, game->p_b, x * IMG, y * IMG);
	else if (game->dir == 'f')
		mlx_put_image_to_window(game->mlx, win, game->p_f, x * IMG, y * IMG);
	else if (game->dir == 'r')
		mlx_put_image_to_window(game->mlx, win, game->p_r, x * IMG, y * IMG);
	else if (game->dir == 'l')
		mlx_put_image_to_window(game->mlx, win, game->p_l, x * IMG, y * IMG);
}

void	display_map(t_game *game, void *mlx, void *win)
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
				mlx_put_image_to_window(mlx, win, game->wa, x * IMG, y * IMG);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, game->b, x * IMG, y * IMG);
			if (game->map[y][x] == 'P')
				display_player(game, game->win, y, x);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, game->c, x * IMG, y * IMG);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, game->e, x * IMG, y * IMG);
			x++;
		}
		y++;
	}
}

void	display_mov(t_game *game)
{
	game->count_step++;
	ft_printf("Number of steps : %d \n", game->count_step);
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
