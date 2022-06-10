/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:48:24 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 10:48:27 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*so1;
	unsigned char	*so2;

	i = 0;
	so1 = (unsigned char *)s1;
	so2 = (unsigned char *)s2;
	while ((so1[i] || so2[i]))
	{
		if (so1[i] != so2[i])
			return (so1[i] - so2[i]);
		i++;
	}	
	return (0);
}
