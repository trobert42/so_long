/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:44:57 by trobert           #+#    #+#             */
/*   Updated: 2022/02/23 16:15:54 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# define BUF_SIZE 20
# define IMG 64
//For qwerty
# define KEY_U 119
# define KEY_D 115
# define KEY_L 97
# define KEY_R 100

//For azerty
/*# define KEY_U 122
# define KEY_D 115
# define KEY_L 113
# define KEY_R 100*/

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include "../../../../../Tools/minilibx-linux/include/mlx.h"

typedef struct	s_game
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
	int		flag_night;
	int		x;
	int		y;
	int		fd;
	void	*wa;
	void	*p_f;
	void	*p_b;
	void	*p_r;
	void	*p_l;
	void	*c;
	void	*e;
	void	*b;
	void	*wa_n;
	void	*p_f_n;
	void	*p_b_n;
	void	*p_r_n;
	void	*p_l_n;
	void	*c_n;
	void	*e_n;
	void	*b_n;
	void	*end;
	void	*start;
	int		start_h;
	int		start_w;
	int	img;
	int	count_c;
	int	count_c_max;
	int	count_step;
	char	dir;
}	t_game;

int		count_char(char *str, char c);
int		check_char(t_game game);
int		get_width(char *line);
int		get_height(t_game game);
t_game	init_map(t_game game, char *argv1);
t_game	read_map(t_game game, char *argv1);
int		check_h(char *str);
int		check_fence(t_game game);
int		is_line(const char *s);
int		ft_strlen_gnl(char *s);
char	*ft_substr_gnl(char *s, int start, int len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(char *src);
char	*getline_cutline(char *str, int flag);
char	*save(char *buf, char *stock, int fd);
int		input(int keysym, t_game *game);
int		start_game(int keysym, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_from_exit(t_game *game, int y, int x);
int		quit_game(t_game *game);
//void	display_map(t_game *game, void *mlx, void *win);
void	display_day_map(t_game *game, void *mlx, void *win);
void	display_night_map(t_game *game, void *mlx, void *win);
void	night_mode(t_game *game);
void	display_map(t_game *game);
void	display_player(t_game *game, void *mlx, void *win, int y, int x);
void	display_mov(t_game *game);
void	display_msg_error(t_game *game);
void	display_start(t_game *game, void *mlx, void *win);
void	display_win(t_game *game, void *mlx, void *win);
void	init_game(t_game *game, int flag_reset);
void	init_night_img(t_game *game, void *mlx);
void	init_night_img_player(t_game *game, void *mlx);
void	reset_game(t_game *game);

#endif
