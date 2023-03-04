/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:53:06 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/15 19:16:20 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*gnl_append_buf(int fd, char *buf, char *joinedbuf)
{
	char	*tmp;
	int		size;

	size = 1;
	while (size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		else if (size == 0)
			break ;
		buf[size] = '\0';
		if (!joinedbuf)
			joinedbuf = ft_strdup("");
		tmp = joinedbuf;
		joinedbuf = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (joinedbuf);
}

char
	*gnl_separate_line_from_joinedbuf(char *line)
{
	size_t	i;
	char	*joinedbuf;

	i = -1;
	while (line[++i] != '\n' && line[i])
		;
	if (!line[i])
		return (NULL);
	joinedbuf = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!*joinedbuf)
	{
		free(joinedbuf);
		joinedbuf = NULL;
	}
	line[i + 1] = '\0';
	return (joinedbuf);
}

char
	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*joinedbuf;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = gnl_append_buf(fd, buf, joinedbuf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	joinedbuf = gnl_separate_line_from_joinedbuf(line);
	return (line);
}
