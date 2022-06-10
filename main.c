/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:07:55 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 10:47:51 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_arg(t_struct *data, char *argv)
{
	if (ft_strcmp(".cub", &argv[ft_strlen(argv) - 4]) != 0)
		print_error(data, "Wrong file extension", 0);
	data->fd = open(argv, O_RDONLY);
	if (data->fd == -1)
		print_error(data, "File does not exist", 0);
	if ((read(data->fd, NULL, 0)) == -1)
	{
		if (errno == EISDIR)
		{
			close(data->fd);
			print_error(data, ".cub is a directory", 0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_struct	data;

	(void)argv;
	if (argc != 2)
		print_error(&data, "Wrong number of arguments", 0);
	data.fd = -1;
	parse_arg(&data, argv[1]);
	init_data(&data);
	set_arg(&data, argv[1]);
	start_game(&data);
	ft_free_game(&data);
	ft_free(&data);
	return (0);
}
