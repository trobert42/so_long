/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:44:57 by trobert           #+#    #+#             */
/*   Updated: 2022/05/23 18:29:15 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H 

# define BUF_SIZE 20

# define IMG 64

# define KEY_U 119
# define KEY_D 115
# define KEY_L 97
# define KEY_R 100

# include "superlibft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_tile
{
	void	*p_f;
	void	*p_b;
	void	*p_r;
	void	*p_l;
	void	*c;
	void	*wa;
	void	*e;
	void	*b;
	void	*end;
	void	*start;
	void	*s1;
	void	*s2;
	void	*s3;
	void	*s4;
	void	*s5;
}	t_tile;

typedef struct s_flag
{
	int	y;
	int	x;
}	t_flag;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	char	**map;
	char	*str_map;
	int		flag_error;
	int		flag_exit;
	int		flag_end;
	int		flag_start;
	int		flag_anim;
	t_flag	flag_mov;
	int		x;
	int		y;
	int		fd;
	int		img;
	int		i_anim;
	int		count_c;
	int		count_c_max;
	int		count_step;
	char	dir;
	t_tile	tile;
}	t_game;

t_game	read_map(t_game game, char *argv1);
int		count_char(char *str, char c);
int		check_char(t_game game);
int		get_width(char *line);
int		get_height(t_game game);
int		check_h(char **tabtab);
int		check_fence(t_game game);
void	check_screen_size(t_game *game);
t_game	init_map(t_game game, char *argv1);
void	init_game(t_game *game, int flag_reset);
void	init_img_anim(t_game *game, void *mlx, int img);
int		start_game(int keysym, t_game *game);
int		input(int keysym, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_from_exit(t_game *game, int y, int x);
void	which_flag_mov(t_game *game, int dir);
void	display_map(t_game *game);
void	display_player(t_game *game, int y, int x);
void	display_start(t_game *game, void *mlx, void *win);
void	display_mov(t_game *game);
void	display_err_quit(int flag, t_game *game, char *str);
void	display_win(t_game *game, void *mlx, void *win);
void	reset_game(t_game *game);
int		quit_game(t_game *game);
int		anim_frame(t_game *game);

#endif
