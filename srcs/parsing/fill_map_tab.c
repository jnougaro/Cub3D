/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:03:36 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:39:19 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_map_tab(t_struct *data, t_arg *arg)
{
	int	i;

	i = 0;
	data->map->map_tab = malloc(sizeof(char *) * ((arg->count - arg->i) + 1));
	if (!data->map->map_tab)
		error_free_arg(data, arg);
	while (i <= (arg->count - arg->i))
	{
		data->map->map_tab[i] = NULL;
		i++;
	}
	get_width(data, arg);
	while (arg->temp_map[arg->i])
	{
		data->map->map_tab[data->map->i] = \
			strdup_square_map(data, arg->temp_map[arg->i]);
		arg->i++;
		data->map->i++;
	}
	data->map->height = count_line(data->map->map_tab);
}

void	find_end_of_tab(t_struct *data)
{
	data->map->eot = count_line(data->map->map_tab);
	while (data->map->eot >= 1 \
			&& data->map->map_tab[data->map->eot - 1][0] == '\0')
		data->map->eot -= 1;
	if (data->map->eot < 3)
		error_map(data);
}
