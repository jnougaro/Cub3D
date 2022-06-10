/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:29:36 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:48:34 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_init_stock(char *stock)
{
	stock = malloc(sizeof(char) * 1);
	if (stock == NULL)
		return (NULL);
	stock[0] = '\0';
	return (stock);
}

void	ft_free_gnl(char **stock)
{
	free(*stock);
	*stock = NULL;
}

int	ft_read(int fd, char *temp)
{
	int	ret;

	ft_bzero_gnl(temp, BUFFER_SIZE + 1);
	ret = read(fd, temp, BUFFER_SIZE);
	return (ret);
}

int	ft_fill_line(char *stock, char **line)
{
	int	i;
	int	j;

	j = 0;
	while (stock[j] && stock[j] != '\n')
		j++;
	*line = malloc(sizeof(char) * (j + 1));
	if (line == NULL)
	{
		free(stock);
		stock = NULL;
		return (-1);
	}
	(*line)[j] = '\0';
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		(*line)[i] = stock[i];
		i++;
	}
	return (i);
}

int	get_next_line(int fd, char **line)
{	
	int			ret;
	static char	*stock = NULL;
	char		temp[BUFFER_SIZE + 1];

	ret = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL || read(fd, temp, 0) == -1)
		return (-1);
	if (stock == NULL)
	{
		stock = ft_init_stock(stock);
		if (stock == NULL)
			return (-1);
	}
	while (ft_strchr_gnl(stock, '\n') == NULL && ret > 0)
	{
		ret = ft_read(fd, temp);
		stock = ft_strjoin_gnl(stock, temp);
	}
	if (ft_fill_line(stock, line) == -1)
		return (-1);
	stock = ft_strdup_gnl(stock);
	if (ret != 0)
		return (1);
	ft_free_gnl(&stock);
	return (0);
}
