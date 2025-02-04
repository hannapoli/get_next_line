/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpolishc <hpolishc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:03:47 by hpolishc          #+#    #+#             */
/*   Updated: 2025/02/04 14:05:31 by hpolishc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (0);
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
	static char	*reserve[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= MAX_FD)
	{
		free(reserve[fd]);
		free(buffer);
		reserve[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	reserve[fd] = ft_read_to_buffer(fd, reserve[fd], buffer);
	line = reserve[fd];
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	reserve[fd] = ft_write_line(line);
	return (line);
}
/* 
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	if ((fd1 < 0) || (fd2 < 0))
	{
		perror("Error opening file");
		return (1);
	}
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	printf("File 1:\n");
	while (line1 != NULL)
	{
		printf("%s\n", line1);
		free(line1);
		line1 = get_next_line(fd1);
	}
	free(line1);
	close(fd1);
	printf("File 2:\n");
	while (line2 != NULL)
	{
		printf("%s\n", line2);
		free(line2);
		line2 = get_next_line(fd2);
	}
	free(line2);
	close(fd2);
	return (0);
}
 */
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