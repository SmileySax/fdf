/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:21:59 by keaton            #+#    #+#             */
/*   Updated: 2022/04/01 22:47:04 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* int	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
} */

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return (NULL);
}

t_map	*ft_free_map(t_map *map)
{
	int	x;

	x = 0;
	if (map->points)
	{
		while ((map->points)[x] && x < map->wid)
			free((map->points)[x++]);
		free((map->points));
	}
	free(map);
	return (NULL);
}

static char	*ft_readword(char const *s, int *i, char c)
{
	int	len;

	len = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		len++;
		(*i)++;
	}
	return (ft_substr(s, *i - len, len));
}

int	ft_countwords(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n;
	int		n1;
	char	**splited;

	if (!s)
		return (NULL);
	i = 0;
	n = ft_countwords(s, c);
	n1 = 0;
	splited = (char **)malloc(sizeof(s) * (n + 1));
	if (!splited)
		return (NULL);
	splited[n] = (void *)0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (splited);
		splited[n1++] = ft_readword(s, &i, c);
		if (!splited[n1 - 1])
			return (ft_free_tab(splited));
	}
	return (splited);
}
