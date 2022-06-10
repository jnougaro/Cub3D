/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:23:40 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:29:01 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	get_texture_color(t_texture *texture, \
	int texture_x, int texture_y)
{
	char	*dest;

	dest = texture->addr + ((int)texture_y * texture->line_length \
		+ (int)texture_x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dest);
}

void	set_texture(t_struct *data)
{
	int	i;

	i = 0;
	data->texture[0]->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, \
		data->coor->no, &data->proj->width_no, &data->proj->height_no);
	data->texture[1]->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, \
		data->coor->so, &data->proj->width_so, &data->proj->height_so);
	data->texture[2]->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, \
		data->coor->we, &data->proj->width_we, &data->proj->height_we);
	data->texture[3]->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, \
		data->coor->ea, &data->proj->width_ea, &data->proj->height_ea);
	while (i < 4)
	{
		get_info_texture(data, data->texture[i]);
		i++;
	}
}

void	get_texture_off_set(t_struct *data, int ray_id)
{
	if (data->ray[ray_id]->hit_no == 1)
		data->proj->offset_x = fmod(data->ray[ray_id]->small_dist_x, 1) \
		* data->proj->width_no;
	else if (data->ray[ray_id]->hit_so == 1)
		data->proj->offset_x = fmod(data->ray[ray_id]->small_dist_x, 1) \
		* data->proj->width_so;
	else if (data->ray[ray_id]->hit_we == 1)
		data->proj->offset_x = fmod(data->ray[ray_id]->small_dist_y, 1) \
		* data->proj->width_we;
	else
		data->proj->offset_x = fmod(data->ray[ray_id]->small_dist_y, 1) \
		* data->proj->width_ea;
}

unsigned int	get_texture_2(t_struct *data, int ray_id, int wall_strip_height)
{
	if (data->ray[ray_id]->hit_we == 1)
	{
		data->proj->offset_y = data->proj->dist_from_top * \
			((double)data->proj->height_we / wall_strip_height);
		return (get_texture_color(data->texture[2], \
			data->proj->offset_x, data->proj->offset_y));
	}
	else
	{
		data->proj->offset_y = data->proj->dist_from_top * \
			((double)data->proj->height_ea / wall_strip_height);
		return (get_texture_color(data->texture[3], data->proj->offset_x, \
			data->proj->offset_y));
	}
}

unsigned int	get_texture(t_struct *data, int ray_id, int wall_strip_height)
{
	if (data->ray[ray_id]->hit_no == 1)
	{
		data->proj->offset_y = data->proj->dist_from_top * \
			((double)data->proj->height_no / wall_strip_height);
		return (get_texture_color(data->texture[0], \
			data->proj->offset_x, data->proj->offset_y));
	}
	else if (data->ray[ray_id]->hit_so == 1)
	{
		data->proj->offset_y = data->proj->dist_from_top * \
			((double)data->proj->height_so / wall_strip_height);
		return (get_texture_color(data->texture[1], \
			data->proj->offset_x, data->proj->offset_y));
	}
	else
		return (get_texture_2(data, ray_id, wall_strip_height));
}
