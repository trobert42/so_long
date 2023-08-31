/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:27:11 by trobert           #+#    #+#             */
/*   Updated: 2022/02/21 15:36:59 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/superlibft.h"

static int	ft_count_words(const char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < ft_strlen(str))
	{
		while (str[i] == c && str[i])
			++i;
		if (str[i])
			++count;
		while (str[i] != c && str[i])
			++i;
		++i;
	}
	return (count);
}

static	void	free_all(char **tab, int k)
{
	while (k >= 0)
	{
		free(tab[k]);
		k--;
	}
	free(tab);
}

static char	*ft_strdup_index(const char *src, int start, int end)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	size = (end - start);
	copy = malloc(sizeof(char) * (size + 1));
	if (copy == NULL)
		return (NULL);
	while (i < size)
	{
		copy[i] = src[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	**ft_split2(char const *str, char c, char **tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < ft_strlen(str))
	{
		while (str[i] == c && i < ft_strlen(str))
			++i;
		j = i;
		if (! str[i])
			break ;
		while (str[i] != c && i < ft_strlen(str))
			++i;
		tab[k] = ft_strdup_index(str, j, i++);
		if (tab[k] == NULL)
		{
			free_all(tab, k - 1);
			return (NULL);
		}
		++k;
	}
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	if (str == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (tab == 0)
		return (NULL);
	tab = ft_split2(str, c, tab);
	tab[ft_count_words(str, c)] = 0;
	return (tab);
}
