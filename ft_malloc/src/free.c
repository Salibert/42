/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:24:23 by salibert          #+#    #+#             */
/*   Updated: 2018/10/19 14:29:58 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/malloc.h"

static void					delete_zone(t_zone *zone, t_zone *previous)
{
	extern t_malloc			g_malloc;

	previous = g_malloc.types[zone->type];
	if (previous == zone)
	{
		if (previous->type == TINY && !zone->next)
		{
			g_malloc.types[previous->type] = zone;
			zone->begin_list->size_block = zone->not_allocated;
			zone->begin_list->next = NULL;
			return ;
		}
		else
			g_malloc.types[previous->type] = zone->next;
	}
	else
		while (previous->next)
			if (previous->next == zone)
			{
				previous->next = zone->next;
				break ;
			}
			else
				previous = previous->next;
	munmap(zone, zone->size_z + cal_q_size(sizeof(t_zone), TINY, 0));
}

static unsigned char		lock_and_free_ptr_in_zone(t_zone *zone, void *ptr)
{
	t_list					*list;
	t_list					*deframent;
	extern t_malloc			g_malloc;

	deframent = NULL;
	list = zone->begin_list;
	if (ptr < (void*)list + OFFSET_PTR || ((void*)list + zone->size_z) <= ptr)
		return (FALSE);
	while (list)
	{
		deframenter(&deframent, &list);
		if ((void*)list + OFFSET_PTR == ptr)
		{
			zone->not_allocated += list->size_block;
			list->is_free = TRUE;
			ft_memset((void*)list + OFFSET_PTR, 0, 8);
			if ((zone->not_allocated + OFFSET_PTR) == zone->size_z)
				delete_zone(zone, NULL);
			return (TRUE);
		}
		list = list->next;
	}
	return (FALSE);
}

static int					search_zone(t_zone *search, void *ptr)
{
	t_zone *zone;

	zone = search;
	while (zone)
	{
		if (lock_and_free_ptr_in_zone(zone, ptr))
			return (10);
		zone = zone->next;
	}
	return (1);
}

void						free(void *ptr)
{
	extern t_malloc			g_malloc;
	extern t_mtx_malloc		g_mtx_malloc;
	int						i;

	i = 0;
	if (!g_malloc.initial_malloc)
		init_malloc();
	if (!ptr)
		return ;
	LOCK(&g_mtx_malloc.g_malloc);
	while (i < 3)
		i += search_zone(g_malloc.types[i], ptr);
	UNLOCK(&g_mtx_malloc.g_malloc);
	return ;
}
