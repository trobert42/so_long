/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/03/01 17:21:05 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	input(int keysym, t_game *game)
{
	if (keysym == 0xff1b)
		quit_game(game);
	else if (keysym == KEY_U)
		move_up(game);
	else if (keysym == KEY_D)
		move_down(game);
	else if (keysym == KEY_R)
		move_right(game);
	else if (keysym == KEY_L)
		move_left(game);
	return (0);
}
