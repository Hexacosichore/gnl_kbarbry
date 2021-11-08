/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:14:12 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/08 17:41:18 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//get_next_line.c

void	*ft_calloc(size_t elementCount, size_t elementSize);
int		ft_strichr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
char	*get_next_line(int fd);

//get_next_line_utils.c

char	*ft_realloc(char *last_malloc,  size_t memorysize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif