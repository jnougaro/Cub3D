/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:50:29 by jnougaro          #+#    #+#             */
/*   Updated: 2021/05/28 11:10:14 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	int		i;
	int		j;
	int		len_s1;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (s1[i] && ft_strchr(set, s1[len_s1]) != NULL)
		len_s1--;
	string = (char *)malloc(sizeof(char) * (len_s1 - i) + 2);
	if (string == NULL)
		return (NULL);
	j = 0;
	while (s1[i] != '\0' && i <= len_s1)
	{
		string[j] = s1[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}
