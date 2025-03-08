/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:57:01 by aalkiz            #+#    #+#             */
/*   Updated: 2025/01/23 04:22:43 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joinstr;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s2)
		return (NULL);
	joinstr = ft_calloc (ft_strlen (s1) + ft_strlen (s2) + 1, sizeof(char));
	if (!joinstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joinstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joinstr[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (joinstr);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < count * size)
		temp[i++] = 0;
	return (temp);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
