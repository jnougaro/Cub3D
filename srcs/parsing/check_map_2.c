/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:01:34 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:03:04 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_around_space(t_struct *data, int i, int j)
{
	if (data->map->map_tab[i][j] \
			&& data->map->map_tab[i][j] != ' ' \
			&& data->map->map_tab[i][j] != '1')
		error_map(data);
}

void	check_up(t_struct *data)
{
	if (data->map->j <= ft_strlen(data->map->map_tab[data->map->i - 1]) - 1)
		check_around_space(data, data->map->i - 1, data->map->j);
	if (data->map->j + 1 <= ft_strlen(data->map->map_tab[data->map->i - 1]) - 1)
		check_around_space(data, data->map->i - 1, data->map->j + 1);
	if (data->map->j != 0)
	{
		if (data->map->j - 1 <= \
			ft_strlen(data->map->map_tab[data->map->i - 1]) - 1)
			check_around_space(data, data->map->i - 1, data->map->j - 1);
	}
}

void	check_down(t_struct *data)
{
	if (data->map->j <= ft_strlen(data->map->map_tab[data->map->i + 1]) - 1)
		check_around_space(data, data->map->i + 1, data->map->j);
	if (data->map->j + 1 <= ft_strlen(data->map->map_tab[data->map->i + 1]) - 1)
		check_around_space(data, data->map->i + 1, data->map->j + 1);
	if (data->map->j != 0)
	{
		if (data->map->j - 1 <= \
			ft_strlen(data->map->map_tab[data->map->i + 1]) - 1)
			check_around_space(data, data->map->i + 1, data->map->j - 1);
	}
}

void	check_current(t_struct *data)
{
	check_around_space(data, data->map->i, data->map->j + 1);
	if (data->map->j != 0)
		check_around_space(data, data->map->i, data->map->j - 1);
}

void	check_space(t_struct *data)
{
	while (data->map->map_tab[data->map->i][data->map->j])
	{
		if (data->map->map_tab[data->map->i][0] == '0' \
				|| data->map->map_tab[data->map->i] \
				[ft_strlen(data->map->map_tab[data->map->i]) - 1] == '0')
			error_map(data);
		if (data->map->map_tab[data->map->i][data->map->j] == ' ')
		{
			if (data->map->i != 0)
				check_up(data);
			if (data->map->map_tab[data->map->i + 1])
				check_down(data);
			if (data->map->map_tab[data->map->i])
				check_current(data);
		}
		data->map->j++;
	}
}
