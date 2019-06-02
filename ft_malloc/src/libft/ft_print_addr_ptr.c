/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:01:03 by salibert          #+#    #+#             */
/*   Updated: 2018/10/19 09:01:05 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_addr_ptr(const void *addr)
{
	write(1, &"0x", 2);
	ft_putnbr_base((unsigned long)addr, 16);
}
