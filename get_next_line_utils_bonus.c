/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpolishc <hpolishc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:03:41 by hpolishc          #+#    #+#             */
/*   Updated: 2025/02/04 14:05:35 by hpolishc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dest = (char *)malloc(len + 1);
	i = 0;
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	character;

	i = 0;
	character = (char) c;
	while (str[i])
	{
		if (str[i] == character)
			return ((char *) &str[i]);
		i++;
	}
	if (character == '\0')
		return ((char *) &str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*main_str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	if ((!str1) || (!str2))
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	main_str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!main_str)
		return (NULL);
	while (i < len1)
	{
		main_str[i] = str1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		main_str[i] = str2[i - len1];
		i++;
	}
	main_str[i] = '\0';
	return (main_str);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		len = 0;
	else if (len > str_len - start)
		len = str_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
