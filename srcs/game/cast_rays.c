/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:31:48 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:14:37 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	normalize_ray(double ray_angle)
{
	ray_angle = remainder(ray_angle, (2 * M_PI));
	if (ray_angle < 0)
		ray_angle = (2 * M_PI) + ray_angle;
	return (ray_angle);
}

double	player_wall_dist(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	cast_one_ray(t_struct *data, t_ray *ray, double ray_angle)
{
	ray_angle = normalize_ray(ray_angle);
	ray->small_dist_x = 0.0;
	ray->small_dist_y = 0.0;
	ray->small_dist = 0.0;
	ray->check_hit_wall_v = 0;
	ray->check_hit_wall_h = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		ray->ray_so = 1;
	else
		ray->ray_so = 0;
	if (ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI))
		ray->ray_ea = 1;
	else
		ray->ray_ea = 0;
	check_hit_horizontal(data, ray, ray_angle);
	check_hit_vertical(data, ray, ray_angle);
	check_nearest_wall(data, ray, ray_angle);
}

void	print_rays(t_struct *data, t_ray *ray, double ray_angle)
{
	double	i;
	double	line;
	int		color;		

	i = 0.0;
	color = rgb_generator(0, 0, 128, 255);
	line = player_wall_dist(ray->small_dist_x, ray->small_dist_y, \
		data->player->pix_x, data->player->pix_y);
	while (i < line)
	{
		if (((data->player->pix_x) + (cos(ray_angle) * (line - i))) < WIN_WIDTH \
			&& ((data->player->pix_y) + (sin(ray_angle) \
			* (line - i))) < WIN_HEIGHT)
		{
			my_pixel_put(data, (data->player->pix_x) + \
				(cos(ray_angle) * (line - i)), \
				(data->player->pix_y) + (sin(ray_angle) * (line - i)), color);
		}
		i++;
	}
}

void	cast_rays(t_struct *data)
{
	int		ray_id;
	double	ray_angle;

	ray_id = 0;
	data->player->rot_angle = normalize_ray(data->player->rot_angle);
	ray_angle = data->player->rot_angle - (data->player->fov / 2);
	while (ray_id < WIN_WIDTH)
	{
		cast_one_ray(data, data->ray[ray_id], ray_angle);
		ray_angle += (data->player->fov / WIN_WIDTH);
		ray_id++;
	}
}
