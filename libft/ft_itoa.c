/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:13:26 by jnougaro          #+#    #+#             */
/*   Updated: 2021/09/07 11:28:05 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_positive(long n, char *dest, int len)
{
	while (len >= 1)
	{
		dest[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (dest);
}

static char	*ft_negative(long n, char *dest, int len)
{
	n *= -1;
	while (len >= 1)
	{
		dest[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	dest[0] = '-';
	return (dest);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			len;
	long int	nbr;

	nbr = (long)n;
	len = ft_len(n);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	if (n < 0)
		return (ft_negative(nbr, dest, len));
	else
		return (ft_positive(nbr, dest, len));
}
