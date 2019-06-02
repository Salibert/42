/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:31:08 by salibert          #+#    #+#             */
/*   Updated: 2016/11/20 17:38:41 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putxy(int x, int y)
{
	ft_putendl("------------------");
	ft_putstr("x -> ");
	ft_putnbr(x);
	ft_putstr("  y -> ");
	ft_putnbr(y);
	ft_putchar('\n');
}
