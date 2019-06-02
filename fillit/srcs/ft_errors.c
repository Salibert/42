/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:00:25 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/27 14:33:25 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_errors(int n)
{
	if (n == -1)
		ft_putstr("error\n");
	if (n == -3)
		ft_putstr("usage: ./fillit 'file' (only one params please)\n");
	if (n == -10)
		ft_putstr("error\n");
	return (0);
}
