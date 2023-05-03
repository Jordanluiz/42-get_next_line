/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfilguei <jfilguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:57:24 by jfilguei          #+#    #+#             */
/*   Updated: 2023/05/01 01:35:50 by jfilguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef MAX_FILES
#  define MAX_FILES 4200
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_read(int fd, char **line_buffer, char *buffer);
char	*ft_free(char **str);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *s, int c, size_t n);
void	ft_free_line(char **line_buffer);
void	ft_new_line(char **line_buffer, char **result);
size_t	ft_strlen(const char *str);

#endif
