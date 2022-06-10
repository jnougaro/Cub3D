/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_print_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:53:02 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:38:18 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int	count_line(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

void	free_param_struct(t_struct *data)
{
	free(data->coor->no);
	data->coor->no = NULL;
	free(data->coor->so);
	data->coor->so = NULL;
	free(data->coor->we);
	data->coor->we = NULL;
	free(data->coor->ea);
	data->coor->ea = NULL;
	free(data->mlx->mlx_ptr);
	data->mlx->mlx_ptr = NULL;
	free(data->mlx->win_ptr);
	data->mlx->win_ptr = NULL;
	free(data->img->img);
	data->img->img = NULL;
	free(data->img->addr);
	data->img->addr = NULL;
}

void	ft_free(t_struct *data)
{
	free_param_struct(data);
	free(data->map);
	data->map = NULL;
	free(data->coor);
	data->coor = NULL;
	free(data->rgb_floor);
	data->rgb_floor = NULL;
	free(data->rgb_ceiling);
	data->rgb_ceiling = NULL;
	free(data->mlx);
	data->mlx = NULL;
	free(data->player);
	data->player = NULL;
	free(data->img);
	data->img = NULL;
	free_struct_ray(data, WIN_WIDTH);
	free(data->proj);
	data->proj = NULL;
	free_struct_texture(data, 4);
	exit(1);
}

void	print_error(t_struct *data, char *str, int index)
{
	if (index == 0)
	{
		printf("Error\n");
		printf("%s\n", str);
		exit(1);
	}
	else if (index == 1)
	{
		printf("Error\n");
		printf("%s\n", str);
		ft_free(data);
	}
	else if (index == 2)
	{
		printf("Error\n");
		printf("%s\n", str);
		close(data->fd);
		ft_free(data);
	}
}
