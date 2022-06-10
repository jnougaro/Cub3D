/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:31:07 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:31:20 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_struct_ray(t_struct *data, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(data->ray[i]);
		data->ray[i] = NULL;
		i++;
	}
	free(data->ray);
	data->ray = NULL;
}

void	free_struct_texture(t_struct *data, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(data->texture[i]);
		data->texture[i] = NULL;
		i++;
	}
	free(data->texture);
	data->texture = NULL;
}

void	free_texture(t_struct *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->texture[i]->img)
			mlx_destroy_image(data->mlx->mlx_ptr, data->texture[i]->img);
		i++;
	}
}

void	ft_free_game(t_struct *data)
{
	free_texture(data);
	if (data->img->img)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->img->img);
		data->img->img = NULL;
		data->img->addr = NULL;
	}
	if (data->mlx->win_ptr)
	{
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
		data->mlx->win_ptr = NULL;
	}
	if (data->mlx->mlx_ptr)
		mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx->mlx_ptr);
	data->mlx->mlx_ptr = NULL;
	free_tab(data->map->map_tab, count_line(data->map->map_tab));
	data->map->map_tab = NULL;
}
