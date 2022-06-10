/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:56:03 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 10:58:45 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_rgb_floor(t_struct *data, t_arg *arg, int index, int first)
{
	if (index == 1)
	{
		data->rgb_floor->red = ft_atoi(&arg->temp_map[arg->i][first]);
		if (data->rgb_floor->red < 0 || data->rgb_floor->red > 255)
			error_free_arg(data, arg);
	}
	else if (index == 2)
	{
		data->rgb_floor->green = ft_atoi(&arg->temp_map[arg->i][first]);
		if (data->rgb_floor->green < 0 || data->rgb_floor->green > 255)
			error_free_arg(data, arg);
	}
	else if (index == 3)
	{
		data->rgb_floor->blue = ft_atoi(&arg->temp_map[arg->i][first]);
		if (data->rgb_floor->blue < 0 || data->rgb_floor->blue > 255)
			error_free_arg(data, arg);
	}
}

void	fill_rgb_ceiling(t_struct *data, t_arg *arg, int index, int first)
{
	if (index == 1)
	{
		data->rgb_ceiling->red = ft_atoi(&arg->temp_map[arg->i][first]);
		if (data->rgb_ceiling->red < 0 || data->rgb_ceiling->red > 255)
			error_free_arg(data, arg);
	}
	else if (index == 2)
	{
		data->rgb_ceiling->green = ft_atoi(&arg->temp_map[arg->i][first]);
		if (data->rgb_ceiling->green < 0 || data->rgb_ceiling->green > 255)
			error_free_arg(data, arg);
	}
	else if (index == 3)
	{
		data->rgb_ceiling->blue = ft_atoi(&arg->temp_map[arg->i][first]);
		if (data->rgb_ceiling->blue < 0 || data->rgb_ceiling->blue > 255)
			error_free_arg(data, arg);
	}
}

void	check_if_num(t_struct *data, t_arg *arg, int index, char *str)
{
	int	first;

	first = arg->j;
	while (arg->temp_map[arg->i][arg->j] \
		&& arg->temp_map[arg->i][arg->j] != ' ' \
		&& arg->temp_map[arg->i][arg->j] != '	' \
		&& arg->temp_map[arg->i][arg->j] != ',')
	{
		if (ft_isdigit(arg->temp_map[arg->i][arg->j]) == 0)
			error_free_arg(data, arg);
		arg->j++;
	}
	if ((arg->j - first) > 3)
		error_free_arg(data, arg);
	if (strcmp("F", str) == 0)
		fill_rgb_floor(data, arg, index, first);
	else if (strcmp("C", str) == 0)
		fill_rgb_ceiling(data, arg, index, first);
}

void	count_comma(t_struct *data, t_arg *arg)
{
	int	count_comma;

	count_comma = 0;
	while (arg->temp_map[arg->i][arg->j] \
		&& (arg->temp_map[arg->i][arg->j] == ' ' \
		|| arg->temp_map[arg->i][arg->j] == '	' \
		|| arg->temp_map[arg->i][arg->j] == ','))
	{
		if (arg->temp_map[arg->i][arg->j] == ',')
			count_comma += 1;
		arg->j++;
	}
	if (count_comma > 1)
		error_free_arg(data, arg);
}	

void	check_info_rgb(t_struct *data, t_arg *arg, char *str)
{
	check_if_num(data, arg, 1, str);
	count_comma(data, arg);
	check_if_num(data, arg, 2, str);
	count_comma(data, arg);
	check_if_num(data, arg, 3, str);
	if (arg->temp_map[arg->i][arg->j] == ',')
		error_free_arg(data, arg);
}	
