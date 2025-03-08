/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:57:11 by aalkiz            #+#    #+#             */
/*   Updated: 2025/01/29 12:02:49 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_line_set(char *str);
char	*ft_rest_set(char *str);
char	*ft_read_line(int fd, char *str);

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s, int c);

#endif