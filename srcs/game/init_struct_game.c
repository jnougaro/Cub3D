/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:18:21 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:18:42 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player(t_struct *data)
{
	data->player = malloc(sizeof(t_player) * 1);
	if (!data->player)
		ft_free(data);
	data->player->walk_dir = 0;
	data->player->turn_dir = 0;
	data->player->press_cam_r = 0;
	data->player->press_cam_l = 0;
	data->player->x = 0.0;
	data->player->y = 0.0;
	data->player->pix_x = 0.0;
	data->player->pix_y = 0.0;
	data->player->rot_speed = 2 * (M_PI / 180);
	data->player->rot_angle = 0.0;
	data->player->strafing_angle = 0.0;
	data->player->fov = 60 * (M_PI / 180);
}

void	init_ray_2(t_struct *data, int i)
{
	data->ray[i]->check_x = 0.0;
	data->ray[i]->check_y = 0.0;
	data->ray[i]->x_step = 0.0;
	data->ray[i]->y_step = 0.0;
	data->ray[i]->hit_wall_hor_x = 0.0;
	data->ray[i]->hit_wall_hor_y = 0.0;
	data->ray[i]->hit_wall_ver_x = 0.0;
	data->ray[i]->hit_wall_ver_y = 0.0;
	data->ray[i]->hor_hit_dist = 0.0;
	data->ray[i]->ver_hit_dist = 0.0;
	data->ray[i]->small_dist = 0.0;
	data->ray[i]->small_dist_x = 0.0;
	data->ray[i]->small_dist_y = 0.0;
	data->ray[i]->check_hit_wall_h = 0;
	data->ray[i]->check_hit_wall_v = 0;
	data->ray[i]->correct_wall_dist = 0.0;
	data->ray[i]->ray_no = 0;
	data->ray[i]->ray_so = 0;
	data->ray[i]->ray_we = 0;
	data->ray[i]->ray_ea = 0;
	data->ray[i]->hit_no = 0;
	data->ray[i]->hit_so = 0;
	data->ray[i]->hit_we = 0;
	data->ray[i]->hit_ea = 0;
}	

void	init_ray(t_struct *data)
{
	int	i;

	i = 0;
	data->ray = malloc(sizeof(t_ray) * WIN_WIDTH);
	if (!data->ray)
		ft_free(data);
	while (i < WIN_WIDTH)
	{
		data->ray[i] = malloc(sizeof(t_ray) * 1);
		if (!data->ray[i])
		{
			free_struct_ray(data, i);
			ft_free(data);
		}
		data->ray[i]->first_inter_x = 0.0;
		data->ray[i]->first_inter_y = 0.0;
		data->ray[i]->next_hor_inter_x = 0.0;
		data->ray[i]->next_hor_inter_y = 0.0;
		data->ray[i]->next_ver_inter_x = 0.0;
		data->ray[i]->next_ver_inter_y = 0.0;
		init_ray_2(data, i);
		i++;
	}
}

void	init_texture(t_struct *data)
{
	int	i;

	i = 0;
	data->texture = malloc(sizeof(t_texture) * 4);
	if (!data->texture)
		ft_free(data);
	while (i < 4)
	{
		data->texture[i] = malloc(sizeof(t_texture) * 1);
		if (!data->texture[i])
			ft_free(data);
		data->texture[i]->img = NULL;
		data->texture[i]->addr = NULL;
		data->texture[i]->bits_per_pixel = 0;
		data->texture[i]->line_length = 0;
		data->texture[i]->endian = 0;
		i++;
	}
}

void	init_proj(t_struct *data)
{
	int	i;

	i = 0;
	data->proj = malloc(sizeof(t_proj) * 1);
	if (!data->proj)
		ft_free(data);
	data->proj->dist_proj_plane = 0.0;
	data->proj->proj_wall_height = 0.0;
	data->proj->width_no = 0;
	data->proj->width_so = 0;
	data->proj->width_we = 0;
	data->proj->width_ea = 0;
	data->proj->height_no = 0;
	data->proj->height_so = 0;
	data->proj->height_we = 0;
	data->proj->height_ea = 0;
	data->proj->offset_x = 0;
	data->proj->offset_y = 0;
	data->proj->dist_from_top = 0;
}
