/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:14:18 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/08 17:52:24 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strichr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && ((unsigned char)s[i] != (unsigned char)c))
		i++;
	if ((unsigned char)s[i] == (unsigned char)c)
		return (i + 1);
	if (i == 0)
		return (0);
	if ((unsigned char)s[i] == '\0')
		return (i);
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*ptr;

	ptr = (void *)malloc(elementCount * elementSize);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, elementCount * elementSize);
	return (ptr);
}

void	ft_free(char *buff, char *line)
{
	free(buff);
	free(line);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;
	int			res;
	int			i;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	if (!buff)
		buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = (char *)ft_calloc(1, sizeof(char));
	while (line[ft_strlen(line) - 1] != '\n')
	{
		if (buff[0] == '\0')
		{
			res = read(fd, buff, BUFFER_SIZE);
			buff[res] = '\0';
			if (res == -1)
				ft_free(buff, line);
		}
		i = ft_strichr(buff, '\n');
		line = ft_realloc(line, ft_strlen(line) + i);
		ft_strlcat(line, buff, ft_strlen(line) + i + 1);
		ft_memmove(buff, &buff[i], BUFFER_SIZE);
	}
	return (line);
}
