/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:29:25 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:30:33 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player_2(t_struct *data, double new_player_x, double new_player_y)
{
	if (check_if_map_has_wall(data, new_player_x, new_player_y) == 0)
	{
		data->player->pix_x = new_player_x;
		data->player->pix_y = new_player_y;
	}
}

void	move_player(t_struct *data, int index)
{
	double	move_step;
	double	new_player_x;
	double	new_player_y;

	move_step = 0.0;
	new_player_x = 0.0;
	new_player_y = 0.0;
	if (index == 0)
	{
		move_step = data->player->walk_dir * 0.2;
		new_player_x = data->player->pix_x + \
			cos(data->player->rot_angle) * move_step;
		new_player_y = data->player->pix_y + \
			sin(data->player->rot_angle) * move_step;
	}
	else
	{
		move_step = data->player->turn_dir * 0.2;
		new_player_x = data->player->pix_x + \
			cos(data->player->rot_angle + M_PI / 2) * move_step;
		new_player_y = data->player->pix_y + \
			sin(data->player->rot_angle + M_PI / 2) * move_step;
	}
	move_player_2(data, new_player_x, new_player_y);
}

void	rotate_cam(t_struct *data)
{
	if (data->player->turn_dir != 0)
		return ;
	if (data->player->press_cam_r == 1)
	{
		data->player->rot_angle = normalize_ray(data->player->rot_angle \
			+ 1 * data->player->rot_speed);
		data->player->press_cam_r = 0;
	}
	else if (data->player->press_cam_l == 1)
	{
		data->player->rot_angle = normalize_ray(data->player->rot_angle \
			- 1 * data->player->rot_speed);
		data->player->press_cam_l = 0;
	}
}
