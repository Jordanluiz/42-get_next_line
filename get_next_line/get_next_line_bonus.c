/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfilguei <jfilguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:57:21 by jfilguei          #+#    #+#             */
/*   Updated: 2023/05/01 13:50:10 by jfilguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

void	ft_free_line(char **line_buffer)
{
	size_t	i;
	size_t	len;
	char	*temp;
	char	*new_line;

	i = 0;
	new_line = ft_strchr(*line_buffer, '\n');
	if (!new_line)
	{
		ft_free(line_buffer);
		return ;
	}
	temp = malloc((ft_strlen(new_line)) * sizeof(char));
	len = ft_strlen(*line_buffer) - ft_strlen(new_line) + 1;
	while (len < ft_strlen(*line_buffer))
		temp[i++] = (*line_buffer)[len++];
	temp[i] = '\0';
	ft_free(line_buffer);
	*line_buffer = temp;
	if (**line_buffer == 0)
		ft_free(line_buffer);
}

void	ft_new_line(char **line_buffer, char **result)
{
	size_t	i;
	size_t	len;
	char	*new_line;

	i = 0;
	new_line = ft_strchr(*line_buffer, '\n');
	len = ft_strlen(*line_buffer) - ft_strlen(new_line) + 1;
	*result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return ;
	while (i < len)
	{
		(*result)[i] = (*line_buffer)[i];
		i++;
	}
	(*result)[i] = '\0';
}

int	ft_read(int fd, char **line_buffer, char *buffer)
{
	int		bytes;
	char	*aux;

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0 || buffer == NULL)
	{
		ft_free(line_buffer);
		return (-1);
	}
	if (bytes == 0)
		return (bytes);
	aux = ft_strjoin(*line_buffer, buffer);
	ft_free(line_buffer);
	*line_buffer = aux;
	return (bytes);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		*buffer;
	char		*result;
	static char	*line_buffer[MAX_FILES];

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (ft_strchr(line_buffer[fd], '\n') == NULL && bytes > 0)
		bytes = ft_read(fd, &(line_buffer[fd]), buffer);
	ft_free(&buffer);
	if (bytes == -1 || ft_strlen(line_buffer[fd]) == 0)
		return (NULL);
	ft_new_line(&(line_buffer[fd]), &result);
	ft_free_line(&(line_buffer[fd]));
	return (result);
}
