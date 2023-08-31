/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:43:54 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 12:22:46 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_width(char *line)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int	get_height(t_game game)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (game.map[i])
	{
		i++;
		count++;
	}
	return (count);
}

t_game	read_map(t_game game, char *argv1)
{
	int		ret;
	char	*maptemp;
	char	buf[BUF_SIZE + 1];

	ret = 1;
	game.fd = open(argv1, O_RDONLY);
	if (game.fd == -1)
		printf("FAILED TO OPEN \n");
	ret = read(game.fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	maptemp = ft_strdup_gnl(buf);
	while (ret > 0)
	{
		ret = read(game.fd, buf, BUF_SIZE);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		maptemp = ft_strjoin_gnl(maptemp, buf);
	}
	game.str_map = ft_strdup_gnl(maptemp);
	free(maptemp);
	return (game);
}

int	check_file_ext(char *argv1)
{
	int	size;

	size = ft_strlen(argv1);
	if (size <= 4)
		return (-1);
	if (argv1[size - 1] != 'r')
		return (-1);
	if (argv1[size - 2] != 'e')
		return (-1);
	if (argv1[size - 3] != 'b')
		return (-1);
	if (argv1[size - 4] != '.')
		return (-1);
	return (0);
}

t_game	init_map(t_game game, char *argv1)
{
	int	i;

	i = 0;
	if (check_file_ext(argv1) == -1)
	{	
		printf("Erreur\n");
		printf("Problem in the Matrix\n");
		game.flag_error = -1;
		return (game);
	}
	game = read_map(game, argv1);
	game.map = ft_split(game.str_map, '\n');
	game.h = get_height(game);
	game.w = get_width(game.str_map);
/*	printf("str : ---%s--- \n", game.str_map);
	while (i < game.h)
	{
		printf("map.map[%d] : %s \n", i, game.map[i]);
		i++;
	}
	printf("heigth | : %d \n", game.h);
	printf("width <->: %d \n", game.w);*/
	if (check_char(game) == -1 || check_h(game.str_map) == -1 \
			|| check_fence(game) == -1)
	{
		printf("Erreur\n");
		printf("Problem in the Matrix\n");
		game.flag_error = -1;
	}
	return (game);
}
