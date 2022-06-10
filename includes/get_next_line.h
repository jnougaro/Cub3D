/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:04:36 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 10:38:12 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 30
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_init_stock(char *stock);
void	ft_free_gnl(char **stock);
int		ft_read(int fd, char *temp);
int		ft_fill_line(char *stock, char **line);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strdup_gnl(char *s1);
void	ft_bzero_gnl(void *s, size_t n);

#endif
