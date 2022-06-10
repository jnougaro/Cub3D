/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:49:35 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:38:55 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_width(t_struct *data, t_arg *arg)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (arg->temp_map[i])
	{	
		len = ft_strlen(arg->temp_map[i]);
		if (len > data->map->width)
			data->map->width = len;
		i++;
	}
}

void	get_info_player(t_struct *data, char c)
{
	data->player->x = data->map->j;
	data->player->y = data->map->i;
	data->player->pix_x = (data->player->x + 0.5) * MINI_CUB_SIZE;
	data->player->pix_y = (data->player->y + 0.5) * MINI_CUB_SIZE;
	if (c == 'N')
		data->player->rot_angle = 1.5 * M_PI;
	else if (c == 'S')
		data->player->rot_angle = 0.5 * M_PI;
	else if (c == 'E')
		data->player->rot_angle = 0.0 * M_PI;
	else if (c == 'W')
		data->player->rot_angle = 1.0 * M_PI;
}	

int	check_char_map(t_struct *data, char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' \
			|| c == 'E' || c == 'W' || c == ' ')
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			data->map->player += 1;
			get_info_player(data, c);
		}
		return (1);
	}
	return (0);
}

void	check_ends(t_struct *data)
{
	int	i;

	i = 0;
	while (data->map->map_tab[i][data->map->j])
	{
		if (data->map->map_tab[i][data->map->j] != ' ' \
				&& data->map->map_tab[i][data->map->j] != '1')
			error_map(data);
		data->map->j++;
	}
	i = data->map->eot - 1;
	data->map->j = 0;
	while (data->map->map_tab[i][data->map->j])
	{
		if (data->map->map_tab[i][data->map->j] != ' ' \
				&& data->map->map_tab[i][data->map->j] != '1')
			error_map(data);
		data->map->j++;
	}
}	

void	parse_map(t_struct *data)
{
	data->map->i = 0;
	while (data->map->map_tab[data->map->i])
	{
		data->map->j = 0;
		while (data->map->map_tab[data->map->i][data->map->j])
		{
			if (check_char_map(data, data->map->map_tab[data->map->i] \
					[data->map->j]) == 0 || data->map->player > 1)
				error_map(data);
			data->map->j++;
		}
		data->map->i++;
	}
	if (data->map->player == 0)
		error_map(data);
	data->map->i = 0;
	data->map->j = 0;
	find_end_of_tab(data);
	check_ends(data);
	while (data->map->map_tab[data->map->i])
	{
		data->map->j = 0;
		check_space(data);
		data->map->i++;
	}
}
