/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:30:46 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:30:57 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx(t_struct *data)
{
	data->mlx = malloc(sizeof(t_mlx) * 1);
	if (!data->mlx)
		ft_free(data);
	data->mlx->mlx_ptr = NULL;
	data->mlx->win_ptr = NULL;
}

void	init_img(t_struct *data)
{
	data->img = malloc(sizeof(t_img) * 1);
	if (!data->img)
		ft_free(data);
	data->img->img = NULL;
	data->img->addr = NULL;
	data->img->bits_per_pixel = 0;
	data->img->line_length = 0;
	data->img->endian = 0;
}
