/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:58:13 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/02/27 13:12:25 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	joined = malloc((ft_strlen(str) + ft_strlen(buffer) + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	i = -1;
	if (str)
		while (str[++i])
			joined[i] = str[i];
	j = 0;
	while (buffer[j])
		joined[i++] = buffer[j++];
	joined[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	free(str);
	return (joined);
}

char	*remove_prev_line(char *s)
{
	char	*removed;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	removed = (char *)malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!removed)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		removed[j++] = s[i++];
	removed[j] = '\0';
	free(s);
	return (removed);
}
