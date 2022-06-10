/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:53:15 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 10:53:33 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_rgb(t_struct *data)
{
	data->rgb_floor = malloc(sizeof(t_rgb) * 1);
	if (!data->rgb_floor)
		ft_free(data);
	data->rgb_ceiling = malloc(sizeof(t_rgb) * 1);
	if (!data->rgb_ceiling)
		ft_free(data);
	data->rgb_floor->red = -1;
	data->rgb_floor->green = -1;
	data->rgb_floor->blue = -1;
	data->rgb_ceiling->red = -1;
	data->rgb_ceiling->green = -1;
	data->rgb_ceiling->blue = -1;
}

void	init_coor(t_struct *data)
{
	data->coor = malloc(sizeof(t_coordinates) * 1);
	if (!data->coor)
		ft_free(data);
	data->coor->no = NULL;
	data->coor->so = NULL;
	data->coor->we = NULL;
	data->coor->ea = NULL;
}

void	init_map(t_struct *data)
{
	data->map = malloc(sizeof(t_map) * 1);
	if (!data->map)
		ft_free(data);
	data->map->map_tab = NULL;
	data->map->i = 0;
	data->map->player = 0;
	data->map->eot = -1;
	data->map->width = 0;
	data->map->height = 0;
}

void	init_data(t_struct *data)
{
	data->rgb_floor = NULL;
	data->rgb_ceiling = NULL;
	data->coor = NULL;
	data->map = NULL;
	data->mlx = NULL;
	data->player = NULL;
	data->img = NULL;
	data->ray = NULL;
	data->proj = NULL;
	data->texture = NULL;
	init_rgb(data);
	init_coor(data);
	init_map(data);
	init_mlx(data);
	init_player(data);
	init_img(data);
	init_ray(data);
	init_proj(data);
	init_texture(data);
}
