/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 12:28:06 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	input(int keysym, t_game *game)
{
	if (keysym == 0xff1b)
		quit_game(game);
	else if (keysym == KEY_U && game->flag_end == 0 && game->flag_start == 1)
		move_up(game);
	else if (keysym == KEY_D && game->flag_end == 0 && game->flag_start == 1)
		move_down(game);
	else if (keysym == KEY_R && game->flag_end == 0 && game->flag_start == 1)
		move_right(game);
	else if (keysym == KEY_L && game->flag_end == 0 && game->flag_start == 1)
		move_left(game);
	else if (keysym == 114 && game->flag_start == 1)
		reset_game(game);
	else if (keysym == 116 && game->flag_start == 1 && game->flag_end == 0)
		night_mode(game);
	else if (keysym == 0xff0d && game->flag_start == 0)
	{
		game->flag_start++ ;
		display_map(game);
	}
}
