/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:03:21 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:03:23 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*strdup_cub(const char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1) && s1[i] != ' ' && s1[i] != '	')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*strdup_square_map(t_struct *data, char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (data->map->width + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s2[i] = s1[i];
		i++;
	}
	while (i < data->map->width)
	{
		s2[i] = ' ';
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	error_map(t_struct *data)
{
	free_tab(data->map->map_tab, count_line(data->map->map_tab));
	print_error(data, "Parameters of the map are invalid", 1);
}

void	error_free_arg(t_struct *data, t_arg *arg)
{
	free_tab(arg->temp_map, count_line(arg->temp_map));
	print_error(data, "Parameters are invalid", 1);
}
