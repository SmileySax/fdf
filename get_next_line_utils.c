/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:23:16 by keaton            #+#    #+#             */
/*   Updated: 2022/04/01 22:41:08 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	ch;

	str = (char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (str[i] != ch && str[i] != '\0')
		i++;
	if (str[i] == '\0' && ch != 0)
		return (NULL);
	return (str + i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	ctr;

	ctr = 0;
	while (*(src + ctr) != '\0')
	{
		*(dest + ctr) = *(src + ctr);
		ctr++;
	}
	*(dest + ctr) = '\0';
	return (dest);
}

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, str);
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*news;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	news = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (news == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		news[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		news[i] = *s2;
		i++;
		s2++;
	}
	news[i] = '\0';
	return (news);
}
