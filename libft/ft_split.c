/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:09:20 by jnougaro          #+#    #+#             */
/*   Updated: 2021/05/28 11:34:13 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char ***dest, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free((*dest)[i]);
		i++;
	}
	free(*dest);
	*dest = NULL;
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (i > 0)
		{
			if (s[i - 1] == c && s[i] != c)
				result++;
		}
		else
		{
			if (s[i] != c)
				result++;
		}
		i++;
	}
	return (result);
}

static char	*ft_strdup_split(const char *s1, char c)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1) && s1[i] != c)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static void	ft_fill_tab(char const *s, char ***dest, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < ft_count_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c)
		{
			(*dest)[j] = ft_strdup_split(&s[i], c);
			if ((*dest)[j] == NULL)
			{
				ft_free(dest, j);
				return ;
			}	
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	(*dest)[j] = NULL;
}

char	**ft_split(char const *s, char c)
{	
	char	**dest;

	if (s == NULL)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (dest == NULL)
		return (NULL);
	ft_fill_tab(s, &dest, c);
	return (dest);
}
