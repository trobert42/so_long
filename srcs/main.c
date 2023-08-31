/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2023/02/10 19:05:36 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;

	game.flag_error = 0;
	if (argc != 2)
		display_err_quit(0, &game, "Numbers of args' different than 2");
	game = init_map(game, argv[1]);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		display_err_quit(0, &game, "Problem with the init of mlx");
	game.win = mlx_new_window(game.mlx, IMG * game.w, (IMG * game.h), \
			"Sacre Bout de Tronc");
	if (game.win == NULL)
		display_err_quit(0, &game, "Problem with the init of win");
	init_game(&game);
	check_screen_size(&game);
	display_map(&game, game.mlx, game.win);
	mlx_hook(game.win, 2, 1L >> 0, input, &game);
	mlx_hook(game.win, 33, 1L >> 2, quit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
