/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:57:08 by aalkiz            #+#    #+#             */
/*   Updated: 2025/01/29 12:01:56 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line_set(char *str)
{
	char	*line;
	int		len;

	len = 0;
	if (!str[len])
		return (NULL);
	while (str[len] != '\n' && str[len])
		len++;
	line = ft_calloc(len + 2, sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (str[len] != '\n' && str[len])
	{
		line[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
		line[len] = '\n';
	return (line);
}

char	*ft_rest_set(char *str)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
	{
		rest[j] = str[i];
		i++;
		j++;
	}
	free(str);
	return (rest);
}

char	*ft_read_line(int fd, char *str)
{
	char	*buffer;
	int		byte_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read != 0 && !ft_strchr(str, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	rest = ft_read_line(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_line_set(rest);
	rest = ft_rest_set(rest);
	return (line);
}
