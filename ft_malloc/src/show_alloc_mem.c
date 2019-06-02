/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:51:16 by salibert          #+#    #+#             */
/*   Updated: 2018/10/19 14:00:59 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/malloc.h"

static t_list			*print_list(t_list *list, size_t *total_allocated)
{
	extern t_malloc		g_malloc;

	if (!(list->is_free))
	{
		ft_print_addr_ptr((void*)list + OFFSET_PTR);
		write(1, &" - ", 3);
		ft_print_addr_ptr(
			(void*)list + OFFSET_PTR + list->size_block - OFFSET_PTR);
		write(1, &" : ", 3);
		ft_putnbr_base(list->size_block - OFFSET_PTR, 10);
		*total_allocated += (list->size_block - OFFSET_PTR);
		write(1, &" octets\n", 8);
	}
	return (list->next);
}

static t_zone			*print_zone(t_zone *zone, size_t *total_allocated)
{
	t_list				*list;

	if (!(zone->type ^ TINY))
		ft_putstr("TINY: ");
	else if (!(zone->type ^ SMALL))
		ft_putstr("SMALL: ");
	else
		ft_putstr("LARGE: ");
	ft_print_addr_ptr(zone);
	write(1, &" octets\n", 8);
	list = zone->begin_list;
	while (list)
		list = print_list(list, total_allocated);
	return (zone->next);
}

void					put_bottom_data(int *array, size_t t_a)
{
	write(1, &"Nb zone: ", 9);
	write(1, &"TINY: ", 6);
	ft_putnbr_base(array[0], 10);
	write(1, &" SMALL: ", 8);
	ft_putnbr_base(array[1], 10);
	write(1, &" LARGE: ", 8);
	ft_putnbr_base(array[2], 10);
	write(1, &" Total Zone : ", 14);
	ft_putnbr_base((array[0] + array[1] + array[2]), 10);
	write(1, &"\nTotal Memory Allocated: ", 25);
	ft_putnbr_base(t_a, 10);
	write(1, &" octets\n", 8);
}

void					show_alloc_mem(void)
{
	size_t				total_allocated;
	extern t_malloc		g_malloc;
	extern t_mtx_malloc	g_mtx_malloc;
	t_zone				*zone;
	int					nb_zone[4];

	total_allocated = 0;
	nb_zone[3] = 0;
	if (!g_malloc.initial_malloc)
		init_malloc();
	LOCK(&g_mtx_malloc.g_malloc);
	while (nb_zone[3] < 3)
	{
		nb_zone[nb_zone[3]] = 0;
		zone = g_malloc.types[nb_zone[3]];
		while (zone)
		{
			zone = print_zone(zone, &total_allocated);
			nb_zone[nb_zone[3]]++;
		}
		nb_zone[3]++;
	}
	UNLOCK(&g_mtx_malloc.g_malloc);
	put_bottom_data(nb_zone, total_allocated);
}
