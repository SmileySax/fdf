/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:22:06 by keaton            #+#    #+#             */
/*   Updated: 2022/06/16 00:57:45 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			res = (char *)(s + i);
			return (res);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*mplace;
	int		i;
	int		n;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	n = 0;
	mplace = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!(mplace))
		return (NULL);
	while (s1[i])
		mplace[n++] = s1[i++];
	i = 0;
	while (s2[i])
		mplace[n++] = s2[i++];
	mplace[n] = '\0';
	return (mplace);
}

char	*ft_strchjoin(char const *s1, char const *s2, char c)
{
	int		l1;
	int		l2;
	char	*mplace;
	int		i;
	int		n;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	n = 0;
	mplace = malloc(sizeof(char) * (l1 + l2 + 2));
	if (!(mplace))
		return (NULL);
	while (s1[i])
		mplace[n++] = s1[i++];
	mplace[n++] = c;
	i = 0;
	while (s2[i])
		mplace[n++] = s2[i++];
	mplace[n] = '\0';
	return (mplace);
} */

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < n && (unsigned char)s1[i] != '\0')
		i++;
	if (i == n)
		return ((int)((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]));
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		l;
	char	*substr;
	int		slen;

	if (!s)
		return (NULL);
	l = 0;
	slen = ft_strlen(s);
	while (start < (unsigned int)slen && (s + start)[l] && l < len)
		l++;
	substr = malloc(sizeof(char) * (l + 1));
	if (!(substr))
		return (NULL);
	substr[l] = '\0';
	while (l > 0)
	{
		substr[l - 1] = (char)(s + start)[l - 1];
		l--;
	}
	return (substr);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sig;
	long int	res;

	i = 0;
	res = 0;
	sig = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + sig * (str[i++] - '0');
	if ((int)res == res)
		return ((int)res);
	else if (sig == -1)
		return (0);
	else
		return (-1);
}
