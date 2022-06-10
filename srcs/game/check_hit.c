/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:19:57 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:23:25 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_first_inter_ver(t_struct *data, t_ray *ray, double ray_angle)
{
	ray->first_inter_x = 0.0;
	ray->first_inter_y = 0.0;
	ray->x_step = 0.0;
	ray->y_step = 0.0;
	ray->first_inter_x = floor(data->player->pix_x / MINI_CUB_SIZE) \
		* MINI_CUB_SIZE;
	if (ray->ray_ea == 1)
		ray->first_inter_x += MINI_CUB_SIZE;
	ray->first_inter_y = data->player->pix_y + \
		(ray->first_inter_x - data->player->pix_x) * tan(ray_angle);
	ray->x_step = MINI_CUB_SIZE;
	if (ray->ray_ea == 0)
		ray->x_step *= -1.0;
	ray->y_step = MINI_CUB_SIZE * tan(ray_angle);
	if (ray->ray_so == 0 && ray->y_step > 0)
		ray->y_step *= -1.0;
	if (ray->ray_so == 1 && ray->y_step < 0)
		ray->y_step *= -1.0;
}

void	check_hit_vertical(t_struct *data, t_ray *ray, double ray_angle)
{
	find_first_inter_ver(data, ray, ray_angle);
	ray->next_ver_inter_x = ray->first_inter_x;
	ray->next_ver_inter_y = ray->first_inter_y;
	while (ray->next_ver_inter_x >= 0 && ray->next_ver_inter_x <= WIN_WIDTH \
		&& ray->next_ver_inter_y >= 0 && ray->next_ver_inter_y <= WIN_HEIGHT)
	{
		ray->check_y = ray->next_ver_inter_y;
		if (ray->ray_ea == 0)
			ray->check_x = ray->next_ver_inter_x - 1.0;
		else
			ray->check_x = ray->next_ver_inter_x;
		if (check_if_map_has_wall(data, ray->check_x, ray->check_y) == 1)
		{
			ray->hit_wall_ver_x = ray->next_ver_inter_x;
			ray->hit_wall_ver_y = ray->next_ver_inter_y;
			ray->check_hit_wall_v = 1;
			break ;
		}
		else
		{
			ray->next_ver_inter_x += ray->x_step;
			ray->next_ver_inter_y += ray->y_step;
		}
	}
}

void	find_first_inter_hor(t_struct *data, t_ray *ray, double ray_angle)
{
	ray->first_inter_y = floor(data->player->pix_y / MINI_CUB_SIZE) \
		* MINI_CUB_SIZE;
	if (ray->ray_so == 1)
		ray->first_inter_y += MINI_CUB_SIZE;
	ray->first_inter_x = data->player->pix_x + \
		(ray->first_inter_y - data->player->pix_y) / tan(ray_angle);
	ray->y_step = MINI_CUB_SIZE;
	if (ray->ray_so == 0)
		ray->y_step *= -1.0;
	ray->x_step = MINI_CUB_SIZE / tan(ray_angle);
	if (ray->ray_ea == 0 && ray->x_step > 0)
		ray->x_step *= -1.0;
	if (ray->ray_ea == 1 && ray->x_step < 0)
		ray->x_step *= -1.0;
}

void	check_hit_horizontal(t_struct *data, t_ray *ray, double ray_angle)
{
	find_first_inter_hor(data, ray, ray_angle);
	ray->next_hor_inter_x = ray->first_inter_x;
	ray->next_hor_inter_y = ray->first_inter_y;
	while (ray->next_hor_inter_x >= 0 && ray->next_hor_inter_x <= WIN_WIDTH \
		&& ray->next_hor_inter_y >= 0 && ray->next_hor_inter_y <= WIN_HEIGHT)
	{
		ray->check_x = ray->next_hor_inter_x;
		if (ray->ray_so == 0)
			ray->check_y = ray->next_hor_inter_y - 1.0;
		else
			ray->check_y = ray->next_hor_inter_y;
		if (check_if_map_has_wall(data, ray->check_x, ray->check_y) == 1)
		{
			ray->hit_wall_hor_x = ray->next_hor_inter_x;
			ray->hit_wall_hor_y = ray->next_hor_inter_y;
			ray->check_hit_wall_h = 1;
			break ;
		}
		else
		{
			ray->next_hor_inter_x += ray->x_step;
			ray->next_hor_inter_y += ray->y_step;
		}
	}
}
