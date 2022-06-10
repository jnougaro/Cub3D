/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_coor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:53:59 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:40:17 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_path_texture(t_struct *data, t_arg *arg, char *str)
{
	if (ft_strcmp("F", str) == 0 || ft_strcmp("C", str) == 0)
		arg->j += 1;
	else
		arg->j += 2;
	if (!arg->temp_map[arg->i][arg->j] || (arg->temp_map[arg->i][arg->j] != ' ' \
		&& arg->temp_map[arg->i][arg->j] != '	'))
		error_free_arg(data, arg);
	while (arg->temp_map[arg->i][arg->j] \
		&& (arg->temp_map[arg->i][arg->j] == ' ' \
		|| arg->temp_map[arg->i][arg->j] == '	'))
		arg->j++;
	if (ft_strcmp("NO", str) == 0)
		data->coor->no = strdup_cub(&arg->temp_map[arg->i][arg->j]);
	else if (ft_strcmp("SO", str) == 0)
		data->coor->so = strdup_cub(&arg->temp_map[arg->i][arg->j]);
	else if (ft_strcmp("WE", str) == 0)
		data->coor->we = strdup_cub(&arg->temp_map[arg->i][arg->j]);
	else if (ft_strcmp("EA", str) == 0)
		data->coor->ea = strdup_cub(&arg->temp_map[arg->i][arg->j]);
	else if (ft_strcmp("F", str) == 0)
		check_info_rgb(data, arg, str);
	else if (ft_strcmp("C", str) == 0)
		check_info_rgb(data, arg, str);
	check_end_line(data, arg);
}

void	check_id_coor(t_struct *data, t_arg *arg)
{
	if (arg->temp_map[arg->i][arg->j] == 'N' \
		&& arg->temp_map[arg->i][arg->j + 1] == 'O' && data->coor->no == NULL)
		check_path_texture(data, arg, "NO");
	else if (arg->temp_map[arg->i][arg->j] == 'S' \
		&& arg->temp_map[arg->i][arg->j + 1] == 'O' && data->coor->so == NULL)
		check_path_texture(data, arg, "SO");
	else if (arg->temp_map[arg->i][arg->j] == 'W' \
		&& arg->temp_map[arg->i][arg->j + 1] == 'E' && data->coor->we == NULL)
		check_path_texture(data, arg, "WE");
	else if (arg->temp_map[arg->i][arg->j] == 'E' \
		&& arg->temp_map[arg->i][arg->j + 1] == 'A' && data->coor->ea == NULL)
		check_path_texture(data, arg, "EA");
	else if (arg->temp_map[arg->i][arg->j] == 'F' \
		&& (arg->temp_map[arg->i][arg->j + 1] == ' ' \
		|| arg->temp_map[arg->i][arg->j + 1] == '	') \
		&& data->rgb_floor->red == -1)
		check_path_texture(data, arg, "F");
	else if (arg->temp_map[arg->i][arg->j] == 'C' \
		&& (arg->temp_map[arg->i][arg->j + 1] == ' ' \
		|| arg->temp_map[arg->i][arg->j + 1] == '	') \
		&& data->rgb_ceiling->red == -1)
		check_path_texture(data, arg, "C");
	else
		error_free_arg(data, arg);
}

void	check_param(t_struct *data, t_arg *arg)
{
	if (ft_isdigit(arg->temp_map[arg->i][arg->j]) == 1)
	{
		if (check_if_param_empty(data) == 1)
		{
			free_tab(arg->temp_map, count_line(arg->temp_map));
			print_error(data, "Parameters are invalid", 1);
		}
		fill_map_tab(data, arg);
	}
	else if (arg->temp_map[arg->i][arg->j] && arg->temp_map[arg->i][arg->j + 1])
		check_id_coor(data, arg);
	else
	{
		free_tab(arg->temp_map, count_line(arg->temp_map));
		print_error(data, "Parameters are invalid", 1);
	}	
}
