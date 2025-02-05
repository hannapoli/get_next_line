/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpolishc <hpolishc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:03:47 by hpolishc          #+#    #+#             */
/*   Updated: 2025/02/05 09:55:06 by hpolishc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_to_buffer(int fd, char *reserve, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while ((bytes_read > 0) && ((!reserve) || (!ft_strchr(reserve, '\n'))))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(reserve);
			return (NULL);
		}
		if (bytes_read == 0)
			return (reserve);
		buffer[bytes_read] = '\0';
		if (!reserve)
			reserve = ft_strdup("");
		temp = reserve;
		reserve = ft_strjoin(temp, buffer);
		free(temp);
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
		return (NULL);
	reserve = ft_substr(line, len + 1, ft_strlen(line) - len);
	if ((!reserve) || (*reserve == '\0'))
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
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(reserve);
		free(buffer);
		reserve = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	reserve = ft_read_to_buffer(fd, reserve, buffer);
	line = reserve;
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	reserve = ft_write_line(line);
	return (line);
}

//#include <stdio.h>
/*
int	main(void)
{
	int		fd;
	int		line_count;
	char	*gnl;

	line_count = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		line_count++;
		printf("[%d]:%s", line_count, gnl);
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	close(fd);
	return (0);
}
 */
/* int	main(void)
{
	char	*str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			break ;
		printf("%s\n", str);
		free (str);
	}
	return (0);
} */
/* test.txt:

1. Empty file.

2. Only \n.

3. 1 line, no \n:
jbjfnekanrbf26744!ˆ&*((dhbsbjsd))

4. 3 lines with \n:
Here I am going to read a line.
Another line.
...and one more line. 

5. A very long line (a lot of chars) without \n.

6. A very long line (a lot of chars) with \n.

7. Variable lines with \n:

0123456789012345678901234567890123456789xdnds
0123456789012345678901234567890123456789jner

0123456789012345678901234567890123456789nrfbrj


0123456789012345678901234567890123456789sajdnfr



0123456789012345678901234567890123456789sBFHEW

*/