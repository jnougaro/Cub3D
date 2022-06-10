/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:31:37 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:42:07 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_if_map_has_wall(t_struct *data, double x, double y)
{
	int	map_index_x;
	int	map_index_y;

	map_index_x = 0;
	map_index_y = 0;
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (1);
	map_index_x = floor(x / MINI_CUB_SIZE);
	if (map_index_x < 0)
		map_index_x = 0;
	if (map_index_x > data->map->width - 1)
		map_index_x = data->map->width - 1;
	map_index_y = floor(y / MINI_CUB_SIZE);
	if (map_index_y < 0)
		map_index_y = 0;
	if (map_index_y > data->map->height - 1)
		map_index_y = data->map->height - 1;
	if (data->map->map_tab[map_index_y][map_index_x] == '1')
		return (1);
	return (0);
}	

void	find_smallest_dist(t_ray *ray)
{
	if (ray->ver_hit_dist < ray->hor_hit_dist)
	{
		ray->small_dist = ray->ver_hit_dist;
		ray->small_dist_x = ray->hit_wall_ver_x;
		ray->small_dist_y = ray->hit_wall_ver_y;
		ray->hit_no = 0;
		ray->hit_so = 0;
		ray->hit_we = ray->ray_ea;
		ray->hit_ea = !ray->hit_we;
		ray->check_hit_wall_v = 1;
	}
	else
	{
		ray->small_dist = ray->hor_hit_dist;
		ray->small_dist_x = ray->hit_wall_hor_x;
		ray->small_dist_y = ray->hit_wall_hor_y;
		ray->hit_we = 0;
		ray->hit_ea = 0;
		ray->hit_no = ray->ray_so;
		ray->hit_so = !ray->hit_no;
		ray->check_hit_wall_v = 0;
	}
}

void	check_nearest_wall(t_struct *data, t_ray *ray, double ray_angle)
{
	ray->ver_hit_dist = 0.0;
	ray->hor_hit_dist = 0.0;
	if (ray->check_hit_wall_h == 1)
		ray->hor_hit_dist = player_wall_dist(data->player->pix_x, \
		data->player->pix_y, ray->hit_wall_hor_x, ray->hit_wall_hor_y);
	else
		ray->hor_hit_dist = INT_MAX;
	if (ray->check_hit_wall_v == 1)
		ray->ver_hit_dist = player_wall_dist(data->player->pix_x, \
		data->player->pix_y, ray->hit_wall_ver_x, ray->hit_wall_ver_y);
	else
		ray->ver_hit_dist = INT_MAX;
	find_smallest_dist(ray);
	ray->correct_wall_dist = ray->small_dist * \
		cos(ray_angle - data->player->rot_angle);
}
