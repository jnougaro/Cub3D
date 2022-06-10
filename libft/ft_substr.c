/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:25:40 by jnougaro          #+#    #+#             */
/*   Updated: 2021/05/27 18:27:31 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	cpy[len] = '\0';
	i = 0;
	while (s[start + i] && i < len)
	{
		cpy[i] = s[start + i];
		i++;
	}
	return (cpy);
}
