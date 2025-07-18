/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 06:07:09 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/14 06:07:10 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	int (i), (j);
	if (!s1 && !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_readline(int bytes, char *line, int fd)
{
	char	*buf;
	char	*tmp;

	buf = malloc(2);
	if (!buf)
		return (NULL);
	bytes = read(fd, &buf[0], 1);
	if (bytes <= 0)
		return (free(buf), NULL);
	buf[1] = '\0';
	line = ft_strjoin(line, buf);
	while (bytes > 0 && *buf != '\n')
	{
		bytes = read(fd, &buf[0], 1);
		if (bytes <= 0)
			return (free(buf), line);
		buf[1] = '\0';
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
	}
	if (buf)
		free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	int (bytes);
	if (fd < 0)
		return (NULL);
	bytes = 0;
	line = ft_readline(bytes, NULL, fd);
	return (line);
}