/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:19:05 by jnougaro          #+#    #+#             */
/*   Updated: 2021/05/27 11:59:26 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	len_dst = ft_strlen (dst);
	if ((dstsize == 0) || (len_dst > dstsize))
		return (ft_strlen(src) + dstsize);
	if (dstsize > 0)
	{
		while (src[i] && ((len_dst + i) < (dstsize - 1)))
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}	
	return (len_dst + ft_strlen(src));
}
