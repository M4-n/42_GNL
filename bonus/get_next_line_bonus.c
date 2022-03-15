/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:55:00 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/02/28 11:42:19 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_getline(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && (s[i] != '\n'))
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] != '\n'))
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_readline(int fd, char *str)
{
	char	*buffer;
	int		status;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	status = 1;
	while ((!ft_strchr(str, '\n')) && status != 0)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[status] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str_fromline;
	static char	*str_fromread[500];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_fromread[fd] = ft_readline(fd, str_fromread[fd]);
	if (!str_fromread[fd])
		return (NULL);
	str_fromline = ft_getline(str_fromread[fd]);
	str_fromread[fd] = remove_prev_line(str_fromread[fd]);
	return (str_fromline);
}
