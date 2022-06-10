/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:04:49 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:11:28 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_info_texture(t_struct *data, t_texture *texture)
{
	if (texture->img != NULL)
		texture->addr = mlx_get_data_addr(texture->img, \
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (texture->addr == NULL || texture->img == NULL)
	{
		printf("Error\n");
		printf("Invalid texture\n");
		ft_free_game(data);
		ft_free(data);
	}
}

void	find_wall_ends(t_struct *data, int wall_strip_height)
{
	data->proj->wall_top_pix = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
	if (data->proj->wall_top_pix < 0)
		data->proj->wall_top_pix = 0;
	data->proj->wall_bottom_pix = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
	if (data->proj->wall_bottom_pix < 0)
		return ;
	if (data->proj->wall_bottom_pix > WIN_HEIGHT)
		data->proj->wall_bottom_pix = WIN_HEIGHT;
}

void	print_wall(t_struct *data, int ray_id, int wall_strip_height)
{
	int	y;
	int	color;

	color = 0;
	y = -1;
	while (++y < WIN_HEIGHT && y < data->proj->wall_top_pix)
		my_pixel_put(data, ray_id, y, rgb_generator(0, data->rgb_ceiling->red, \
			data->rgb_ceiling->green, data->rgb_ceiling->blue));
	y = data->proj->wall_top_pix;
	while (y < WIN_HEIGHT && y < data->proj->wall_bottom_pix)
	{
		data->proj->dist_from_top = y + \
			(wall_strip_height / 2) - (WIN_HEIGHT / 2);
		data->proj->offset_y = data->proj->dist_from_top * \
			((double)data->proj->height_no / wall_strip_height);
		color = get_texture(data, ray_id, wall_strip_height);
		my_pixel_put(data, ray_id, y, color);
		y++;
	}
	y = data->proj->wall_bottom_pix - 1;
	while (++y > 0 && y < WIN_HEIGHT)
		my_pixel_put(data, ray_id, y, rgb_generator(0, data->rgb_floor->red, \
			data->rgb_floor->green, data->rgb_floor->blue));
}

void	render_3d_wall(t_struct *data)
{
	int				i;
	int				wall_strip_height;

	i = 0;
	data->proj->dist_proj_plane = (WIN_WIDTH / 2) / tan(data->player->fov / 2);
	while (i < WIN_WIDTH)
	{
		data->proj->proj_wall_height = (MINI_CUB_SIZE / \
			data->ray[i]->correct_wall_dist) * data->proj->dist_proj_plane;
		wall_strip_height = (int)data->proj->proj_wall_height;
		get_texture_off_set(data, i);
		find_wall_ends(data, wall_strip_height);
		print_wall(data, i, wall_strip_height);
		i++;
	}
}
