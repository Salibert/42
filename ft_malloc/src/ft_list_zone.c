/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_zone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:29:58 by salibert          #+#    #+#             */
/*   Updated: 2018/10/15 14:12:51 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/malloc.h"

void		ft_push_back_zone(t_zone **alst, t_zone *new)
{
	t_zone	*list;

	if (*alst)
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*alst = new;
}

void		ft_delete_zone(t_zone **alst, t_zone *delete)
{
	t_zone	*list;
	t_zone	*tmp;

	if (*alst)
	{
		list = *alst;
		while (list->next)
		{
			if (list == delete)
			{
				tmp->next = list->next;
				return ;
			}
			tmp = list;
			list = list->next;
		}
	}
}
