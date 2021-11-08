/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:14:21 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/08 17:10:21 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size_des;
	unsigned int	size_src;

	size_des = ft_strlen(dst);
	size_src = ft_strlen(src);
	i = size_des;
	j = 0;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	if (size > 0 && i > 0)
		dst[i] = '\0';
	if (size < size_des)
		return (size_src + size);
	return (size_des + size_src);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dest2;

	if (!src && !dest)
		return (0);
	i = 0;
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dest2;

	if (!src && !dest)
		return (0);
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
	{
		src2 = (unsigned char *)src;
		dest2 = (unsigned char *)dest;
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	return (dest);
}

char	*ft_realloc(char *last_malloc,  size_t memorysize)
{
	char	*new_malloc;

	new_malloc = (char *)ft_calloc(memorysize, sizeof(char));
	if(!new_malloc)
		return (NULL);
	ft_memcpy(new_malloc, last_malloc, ft_strlen(last_malloc));
	free(last_malloc);
	return (new_malloc);
}