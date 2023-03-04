/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtorres- <xtorres-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:48:08 by xtorres-          #+#    #+#             */
/*   Updated: 2023/03/02 17:48:10 by xtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>	/* Malloc & Free functions */
# include <unistd.h> 	/* Read functions */
# include <stdio.h>		/* BUFSIZ definition*/
# include <fcntl.h> 	/* Open function */
# include <limits.h>	/* Macro defined OPEN_MAX */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806L /*Double long*/
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_get_line(char *s, char **rest);
char	*ft_strchr(const char *s, int c);
char	*ft_join_ptr(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_get_rest(char *s);

#endif
