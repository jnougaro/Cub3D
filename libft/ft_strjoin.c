/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:18:30 by jnougaro          #+#    #+#             */
/*   Updated: 2021/05/28 10:57:23 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (s1 && s2)
	{
		dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (dest == NULL)
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
			dest[i++] = s2[j++];
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
