/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:22:59 by keaton            #+#    #+#             */
/*   Updated: 2022/06/16 00:57:18 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
int		get_next_line(int fd, char **str);

#endif
