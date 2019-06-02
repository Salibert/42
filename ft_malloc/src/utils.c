/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:56:13 by salibert          #+#    #+#             */
/*   Updated: 2018/10/19 08:53:37 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/malloc.h"

void					deframenter(t_list **previous, t_list **current)
{
	extern t_malloc		g_malloc;

	if ((*current)->is_free)
	{
		if (!(*previous))
			*previous = *current;
		else
		{
			(*previous)->size_block += (*current)->size_block;
			(*previous)->next = (*current)->next;
			*current = *previous;
		}
	}
	else if (*previous)
		*previous = NULL;
}

size_t					cal_q_size(size_t size, int type, int offset)
{
	size_t				size_w_offset;
	int					size_q;

	size_w_offset = size + offset;
	if (!(type ^ TINY))
		size_q = TINY_QUANTIUM;
	else if (!(type ^ SMALL))
		size_q = SMALL_QUANTIUM;
	else
		size_q = LARGE_QUANTIUM;
	if ((size_w_offset % size_q) ^ 0)
		size_w_offset = size_w_offset + (size_q - (size_w_offset % size_q));
	return (size_w_offset);
}

size_t					get_type_zone(size_t size)
{
	if (size <= 0)
		return (-1);
	if (size <= SIZE_MAX_TINY)
		return (TINY);
	if (size <= SIZE_MAX_SMALL)
		return (SMALL);
	return (LARGE);
}

size_t					get_size_z_by_type(size_t size, int type)
{
	extern t_malloc		g_malloc;

	if (type == TINY || type == SMALL)
		return (g_malloc.size[type]);
	return (size + (g_malloc.page_size - (size % g_malloc.page_size)) * 100);
}

t_malloc g_malloc = { 0, 0, 0, { NULL, NULL, NULL}, {0, 0} };

t_mtx_malloc g_mtx_malloc = { PTHREAD_MUTEX_INITIALIZER };

void					init_malloc(void)
{
	extern t_mtx_malloc	g_mtx_malloc;
	extern t_malloc		g_malloc;
	int					i;

	i = 0;
	LOCK(&g_mtx_malloc.g_malloc);
	g_malloc.page_size = getpagesize();
	while (i < 3)
	{
		g_malloc.types[i] = NULL;
		if (i < 2)
			g_malloc.size[i] = ((i) ?
				SIZE_SMALL : SIZE_TINY)
				* g_malloc.page_size;
		i++;
	}
	g_malloc.offset_ptr = cal_q_size(sizeof(t_list), TINY, 0);
	g_malloc.initial_malloc += 1;
	UNLOCK(&g_mtx_malloc.g_malloc);
}
