/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:57:10 by salibert          #+#    #+#             */
/*   Updated: 2018/10/19 13:10:13 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/malloc.h"

static unsigned char	manage_realloc(t_list *list,
									void **ptr, size_t size, t_zone *zone)
{
	void				*new_ptr;
	size_t				len_cpy;
	int					type;
	extern t_malloc		g_malloc;
	extern t_mtx_malloc g_mtx_malloc;

	new_ptr = NULL;
	len_cpy = 0;
	type = get_type_zone(size);
	if (type == zone->type && list->size_block >= size &&
		list->size_block <= cal_q_size(size, type, g_malloc.initial_malloc))
		return (TRUE);
	UNLOCK(&g_mtx_malloc.g_malloc);
	if ((new_ptr = malloc(size)))
	{
		len_cpy = list->size_block > size ? size : list->size_block;
		ft_memcpy(new_ptr, *ptr, len_cpy);
		free(*ptr);
		*ptr = new_ptr;
		return (TRUE);
	}
	LOCK(&g_mtx_malloc.g_malloc);
	return (FALSE);
}

static unsigned char	localized_ptr(t_zone *zone, void **ptr, size_t size)
{
	t_list				*list;
	t_list				*deframent;
	extern t_malloc		g_malloc;

	deframent = NULL;
	list = zone->begin_list;
	if ((*ptr) < (void*)list + OFFSET_PTR ||
		((void*)list + zone->size_z) <= (*ptr))
		return (FALSE);
	while (list)
	{
		if ((void*)list + OFFSET_PTR == (*ptr))
			return (manage_realloc(list, ptr, size, zone));
		deframenter(&deframent, &list);
		list = list->next;
	}
	return (FALSE);
}

static int				search_zone(t_zone *search, void **ptr, size_t size)
{
	t_zone				*zone;

	zone = search;
	while (zone)
	{
		if (localized_ptr(zone, ptr, size))
			return (10);
		zone = zone->next;
	}
	return (1);
}

void					*realloc(void *ptr, size_t size)
{
	extern t_malloc		g_malloc;
	extern t_mtx_malloc g_mtx_malloc;
	int					i;

	i = 0;
	if (!g_malloc.initial_malloc)
		init_malloc();
	if (!(ptr))
		return (malloc(size));
	LOCK(&g_mtx_malloc.g_malloc);
	while (i < 3)
		i += search_zone(g_malloc.types[i], &ptr, size);
	UNLOCK(&g_mtx_malloc.g_malloc);
	if (i >= 10)
		return (ptr);
	return (NULL);
}
