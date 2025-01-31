/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpolishc <hpolishc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:03:47 by hpolishc          #+#    #+#             */
/*   Updated: 2025/01/31 11:13:43 by hpolishc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_to_buffer(int fd, char *reserve, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(reserve);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!reserve)
			reserve = ft_strdup("");
		temp = reserve;
		reserve = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (reserve);
}

static char	*ft_write_line(char *line)
{
	size_t	len;
	char	*reserve;

	len = 0;
	while ((line[len] != '\0') && (line[len] != '\n'))
		len++;
	if (line[len] == '\0')
		return (0);
	reserve = ft_substr(line, len + 1, ft_strlen(line) - len);
	if (*reserve == '\0')
	{
		free(reserve);
		reserve = NULL;
	}
	line[len + 1] = '\0';
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(reserve);
		free(buffer);
		reserve = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (NULL);
	line = ft_read_to_buffer(fd, reserve, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	reserve = ft_write_line(line);
	return (line);
}
/* 
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		line_count;
	char	*gnl;

	line_count = 0;
	fd = open("test.txt", O_RDONLY | O_CREAT);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		line_count++;
		printf("[%d]:%s\n", line_count, gnl);
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
	return (0);
}
 */