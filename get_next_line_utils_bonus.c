/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtorres- <xtorres-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:48:25 by xtorres-          #+#    #+#             */
/*   Updated: 2023/03/02 17:48:27 by xtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_join_ptr(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	str = (char *) ft_calloc(len_s1 + ft_strlen(s2) + 2, sizeof(char));
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		str[len_s1] = s2[i];
		i++;
		len_s1++;
	}
	str[len_s1] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *) s;
	i = 0;
	if (c == '\0')
		return (&ptr[ft_strlen(ptr)]);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = (void *) malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr_str;

	ptr_str = (char *) s;
	while (n > 0)
	{
		*ptr_str = 0;
		ptr_str++;
		n--;
	}
}
