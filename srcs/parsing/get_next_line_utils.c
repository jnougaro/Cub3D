/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:23:50 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:49:08 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strchr_gnl(const char *s, int c)
{	
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i + 1);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (s1 && s2)
	{
		dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (dest == NULL)
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
			dest[i++] = s2[j++];
		dest[i] = '\0';
		free(s1);
		s1 = NULL;
		return (dest);
	}
	return (NULL);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*s2;
	int		i;
	int		size;

	size = 0;
	while (s1[size] && s1[size] != '\n')
		size++;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) - size + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	if (s1[size])
		size++;
	while (s1[size])
	{
		s2[i] = s1[size++];
		i++;
	}
	s2[i] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (s2);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
