/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:22:36 by zerudo            #+#    #+#             */
/*   Updated: 2022/01/24 17:14:32 by zerudo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

#ifndef BUF_SIZE
# define BUF_SIZE 20
#endif

char	*ft_strjoin_test(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (s1_len + s2_len))
		str[i++] = s2[j++];
	str[s1_len + s2_len] = '\0';
	free(s1);
	return (str);
}

int main()
{
	int fd;
	char *map;
	char **mapfinal;
	int	i = 0;
	int ret = 1;
	char	buf[BUF_SIZE + 1];
	
	fd = open("maps", O_RDONLY);
	if (fd == -1)
	{
		printf("failed to open");
		return(0);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	map = ft_strdup(buf);
	while (ret > 0)
	{
		ret = read(fd, buf, BUF_SIZE);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		map = ft_strjoin_test(map, buf);
		printf("%s \n", map);
	}
	mapfinal = ft_split(map, '\n');
	free(map);
	while(mapfinal[i])
	{
		printf("mapfinal[%d] : [%s] \n", i , mapfinal[i]);
		free(mapfinal[i]);
		i++;
	}
	free(mapfinal);
	return(0);
}
