/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:56:36 by salibert          #+#    #+#             */
/*   Updated: 2018/10/22 10:51:08 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/malloc.h"

static t_zone			*search_great_zone(size_t size, int type)
{
	t_zone				*zone;
	extern t_malloc		g_malloc;

	zone = g_malloc.types[type];
	while (zone)
	{
		if (zone->type == type && zone->not_allocated > size)
			return (zone);
		zone = zone->next;
	}
	return (NULL);
}

static t_zone			*create_new_zone(size_t size, int type)
{
	extern t_malloc		g_malloc;
	t_zone				*new;
	size_t				size_z;
	size_t				offset;

	if ((size_z = get_size_z_by_type(size, type)) >= UINT_MAX)
		return (NULL);
	new = (t_zone*)mmap(NULL, size_z, PROT_READ |
						PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
	if (new == MAP_FAILED)
		return (NULL);
	new->type = type;
	new->next = NULL;
	offset = cal_q_size(sizeof(t_zone), TINY, 0);
	new->size_z = size_z - offset;
	new->begin_list = (t_list*)((void *)new + offset);
	new->begin_list->size_block = new->size_z - OFFSET_PTR;
	new->not_allocated = new->begin_list->size_block;
	new->begin_list->next = NULL;
	new->begin_list->is_free = TRUE;
	ft_push_back_zone(&g_malloc.types[type], new);
	return (new);
}

static void				*create_new_block(t_list *list,
									size_t size, t_zone *zone)
{
	extern t_malloc		g_malloc;
	size_t				not_allocated;
	t_list				*new;

	not_allocated = list->size_block - size;
	list->is_free = FALSE;
	list->size_block = size;
	if (not_allocated <= cal_q_size(0, zone->type, OFFSET_PTR))
		list->size_block = not_allocated + list->size_block;
	else
	{
		new = (void *)list + size;
		zone->not_allocated -= list->size_block;
		new->size_block = not_allocated;
		new->is_free = TRUE;
		new->next = list->next;
		list->next = new;
	}
	return (void*)list + OFFSET_PTR;
}

static void				*get_block(t_zone *zone, size_t size)
{
	t_list				*deframent;
	t_list				*list;

	deframent = NULL;
	if (zone)
	{
		list = zone->begin_list;
		while (list)
		{
			deframenter(&deframent, &list);
			if (list->is_free && list->size_block >= size)
				return (create_new_block(list, size, zone));
			list = list->next;
		}
	}
	return (NULL);
}

void					*malloc(size_t size)
{
	extern t_mtx_malloc	g_mtx_malloc;
	extern t_malloc		g_malloc;
	t_zone				*zone_malloc;
	void				*ptr;
	int					type;

	ptr = NULL;
	if (!g_malloc.initial_malloc)
		init_malloc();
	type = get_type_zone(cal_q_size(size, TINY, 0));
	if (type != -1)
	{
		LOCK(&g_mtx_malloc.g_malloc);
		size = cal_q_size(size, type, OFFSET_PTR);
		if (!(zone_malloc = search_great_zone(size, type)))
			zone_malloc = create_new_zone(size, type);
		ptr = get_block(zone_malloc, size);
		UNLOCK(&g_mtx_malloc.g_malloc);
	}
	return (ptr);
}
