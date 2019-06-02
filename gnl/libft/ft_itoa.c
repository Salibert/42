/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:03:13 by salibert          #+#    #+#             */
/*   Updated: 2016/11/18 17:28:57 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t		i;

	i = 1;
	if (n == 0)
		return (2);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ft_overflow(void)
{
	char		*nb;

	if (!(nb = (char*)malloc(sizeof(*nb) * (12))))
		return (NULL);
	nb = ft_strdup("-2147483648");
	return (nb);
}

char			*ft_itoa(int n)
{
	size_t		i;
	size_t		sign;
	char		*nb;

	sign = 0;
	if (n == -2147483648)
		return (ft_overflow());
	i = ft_size(n);
	if (n < 0)
	{
		i = i + 1;
		sign = 1;
		n *= -1;
	}
	if (!(nb = (char*)malloc(sizeof(*nb) * i)))
		return (NULL);
	nb[--i] = '\0';
	while (i)
	{
		nb[--i] = (n % 10) + 48;
		n /= 10;
	}
	if (sign == 1)
		nb[0] = '-';
	return (nb);
}
