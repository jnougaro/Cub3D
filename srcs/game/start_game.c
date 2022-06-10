/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:15:14 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:17:14 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_window(t_struct *data)
{
	data->mlx->mlx_ptr = mlx_init();
	if (data->mlx->mlx_ptr == NULL)
		ft_free(data);
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, \
		WIN_WIDTH, WIN_HEIGHT, "INTERSTELLAR");
	if (data->mlx->win_ptr == NULL)
	{
		ft_free_game(data);
		ft_free(data);
	}
	data->img->img = mlx_new_image(data->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (data->img->img == NULL)
	{
		ft_free_game(data);
		ft_free(data);
	}
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, \
		&data->img->line_length, &data->img->endian);
	if (data->img->img == NULL)
	{
		ft_free_game(data);
		ft_free(data);
	}
}

int	rgb_generator(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_pixel_put(t_struct *data, int x, int y, int color)
{
	char	*dest;

	dest = data->img->addr + (y * data->img->line_length \
		+ x * (data->img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	window_resized(t_struct *data)
{
	render_game(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, \
		data->mlx->win_ptr, data->img->img, 0, 0);
	return (0);
}

void	start_game(t_struct *data)
{
	init_window(data);
	set_texture(data);
	mlx_hook(data->mlx->win_ptr, 17, 1L << 17, &handle_cross, data);
	mlx_hook(data->mlx->win_ptr, 2, 1L << 0, &handle_keypress, data);
	mlx_hook(data->mlx->win_ptr, 3, 1L << 1, &handle_keyrelease, data);
	mlx_loop_hook(data->mlx->mlx_ptr, &render_game, data);
	mlx_hook(data->mlx->win_ptr, 12, 1L << 15, &window_resized, data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, \
		data->mlx->win_ptr, data->img->img, 0, 0);
	mlx_loop(data->mlx->mlx_ptr);
}
