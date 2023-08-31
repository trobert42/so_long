/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 12:26:11 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;

	game.flag_error = 1;
	game = init_map(game, argv[1]);
	if (game.flag_error == -1)
		exit (0);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		quit_game(&game);
	game.win = mlx_new_window(game.mlx, IMG * game.w, (IMG * game.h), \
			"Sacre Bout de Tronc");
	if (game.win == NULL)
		quit_game(&game);
	init_game(&game, 0);
	if (game.flag_error == -1)
		quit_game(&game);
	display_start(&game, game.mlx, game.win);
	mlx_hook(game.win, 2, 1L >> 0, input, &game);
	mlx_hook(game.win, 33, 1L >> 2, quit_game, &game);
	mlx_loop(game.mlx);
}
