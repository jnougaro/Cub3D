/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:18:57 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:19:38 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	handle_cross(t_struct *data)
{
	ft_free_game(data);
	ft_free(data);
	exit(0);
}

int	render_game(t_struct *data)
{
	if (data->player->walk_dir != 0)
	{
		move_player(data, 0);
		data->player->walk_dir = 0;
	}
	else if (data->player->turn_dir != 0)
	{
		move_player(data, 1);
		data->player->turn_dir = 0;
	}
	if (data->player->press_cam_r == 1)
		rotate_cam(data);
	else if (data->player->press_cam_l == 1)
		rotate_cam(data);
	cast_rays(data);
	render_3d_wall(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, \
		data->mlx->win_ptr, data->img->img, 0, 0);
	return (0);
}

int	handle_keyrelease(int keysym, t_struct *data)
{
	if (keysym == 'w')
		data->player->walk_dir = 0;
	else if (keysym == 'a')
		data->player->turn_dir = 0;
	else if (keysym == 's')
		data->player->walk_dir = 0;
	else if (keysym == 'd')
		data->player->turn_dir = 0;
	if (keysym == XK_Right)
		data->player->press_cam_r = 0;
	else if (keysym == XK_Left)
		data->player->press_cam_l = 0;
	return (0);
}

int	handle_keypress(int keysym, t_struct *data)
{
	if (keysym == XK_Escape)
	{
		ft_free_game(data);
		ft_free(data);
		exit(0);
	}
	if (keysym == 'w')
		data->player->walk_dir = 1;
	else if (keysym == 'a')
		data->player->turn_dir = (-1);
	else if (keysym == 's')
		data->player->walk_dir = (-1);
	else if (keysym == 'd')
		data->player->turn_dir = 1;
	if (keysym == XK_Right)
		data->player->press_cam_r = 1;
	else if (keysym == XK_Left)
		data->player->press_cam_l = 1;
	return (0);
}
