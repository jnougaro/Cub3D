/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:51:32 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:38:39 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_if_param_empty(t_struct *data)
{
	if (data->coor->no == NULL)
		return (1);
	else if (data->coor->so == NULL)
		return (1);
	else if (data->coor->we == NULL)
		return (1);
	else if (data->coor->ea == NULL)
		return (1);
	else if (data->rgb_floor->red == -1)
		return (1);
	else if (data->rgb_ceiling->red == -1)
		return (1);
	return (0);
}

void	check_end_line(t_struct *data, t_arg *arg)
{
	while (arg->temp_map[arg->i][arg->j] \
		&& ft_isprint(arg->temp_map[arg->i][arg->j]) == 1)
		arg->j++;
	while (arg->temp_map[arg->i][arg->j] \
			&& (arg->temp_map[arg->i][arg->j] == ' ' \
			|| arg->temp_map[arg->i][arg->j] == '	'))
		arg->j++;
	if (arg->temp_map[arg->i][arg->j])
	{
		free_tab(arg->temp_map, count_line(arg->temp_map));
		print_error(data, "Parameters are invalid", 1);
	}	
}

void	fill_info(t_struct *data, t_arg *arg)
{
	while (arg->temp_map[arg->i])
	{
		arg->j = 0;
		if (arg->temp_map[arg->i] != NULL)
		{
			while (arg->temp_map[arg->i][arg->j] \
				&& (arg->temp_map[arg->i][arg->j] == ' ' \
				|| arg->temp_map[arg->i][arg->j] == '	'))
				arg->j++;
			if (arg->temp_map[arg->i][arg->j])
				check_param(data, arg);
		}
		if (arg->temp_map[arg->i])
			arg->i++;
	}
	if (!data->map->map_tab)
	{
		free_tab(arg->temp_map, count_line(arg->temp_map));
		print_error(data, "Parameters are invalid", 1);
	}
}
