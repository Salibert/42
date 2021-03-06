/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:54:28 by salibert          #+#    #+#             */
/*   Updated: 2018/10/15 10:54:29 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_base(size_t nb, int base)
{
	size_t	n;
	char	nbr;

	n = nb;
	nbr = '\0';
	if (nb >= (size_t)base)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
	}
	else
	{
		if (base > 10)
			nbr = (n > 9 ? (('a' - 10) + n) : ('0' + n));
		else
			nbr = '0' + n;
		write(1, &nbr, 1);
	}
}
