/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:58:58 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 10:59:48 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_arg(t_arg *arg)
{
	arg->count = 1;
	arg->ret = 0;
	arg->i = 0;
	arg->j = 0;
	arg->line = NULL;
	arg->temp_map = NULL;
}

void	count_file_line(t_struct *data, t_arg *arg)
{
	arg->ret = get_next_line(data->fd, &arg->line);
	if (arg->ret == -1)
		print_error(data, "Get_next_line failed", 2);
	while (arg->ret > 0)
	{
		free(arg->line);
		arg->ret = get_next_line(data->fd, &arg->line);
		arg->count++;
	}
	free(arg->line);
	if (arg->count == 0)
		print_error(data, "The file is empty", 2);
	else if (arg->count < 9)
		print_error(data, "Arguments are invalid", 2);
	close(data->fd);
}

void	fill_temp_map(t_struct *data, t_arg *arg, char *argv)
{
	int	i;

	arg->temp_map = malloc(sizeof(char *) * (arg->count + 1));
	if (!arg->temp_map)
		ft_free(data);
	arg->temp_map[arg->count] = NULL;
	data->fd = open(argv, O_RDONLY);
	arg->ret = get_next_line(data->fd, &arg->temp_map[0]);
	i = 1;
	while (arg->ret > 0)
	{
		arg->ret = get_next_line(data->fd, &arg->temp_map[i]);
		i++;
	}
	close(data->fd);
}

void	set_arg(t_struct *data, char *argv)
{
	t_arg	arg;

	init_arg(&arg);
	count_file_line(data, &arg);
	fill_temp_map(data, &arg, argv);
	fill_info(data, &arg);
	free_tab(arg.temp_map, count_line(arg.temp_map));
	parse_map(data);
}
