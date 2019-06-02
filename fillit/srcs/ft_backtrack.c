/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:51:21 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/27 14:48:29 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int		ft_racine(int nb)
{
	int i;

	i = 0;
	while ((i * i) < nb)
		i++;
	return (i);
}

char	**ft_create_finaltab(int nb)
{
	char	**tab;
	int		i;
	int		n;

	i = 0;
	n = ft_racine(nb * 4);
	if (!(tab = (char**)malloc(sizeof(char*) * (n + 1))))
		return (0);
	tab[n] = 0;
	while (i < n)
	{
		tab[i] = ft_strnew(n);
		tab[i] = ft_memset(tab[i], '.', n);
		i++;
	}
	return (tab);
}

char	**ft_realloc(char **tab)
{
	char	**new;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(tab[0]) + 1;
	if (!(new = (char**)malloc(sizeof(char*) * (len + 1))))
		return (0);
	new[len] = 0;
	while (i < len)
	{
		new[i] = ft_strnew(len);
		new[i] = ft_memset(new[i], '.', len);
		i++;
	}
	return (new);
}

int		ft_backtrack(int *last, int i, char **tab, int nb)
{
	int		x;
	int		y;
	int		len;
	t_tt	*tabf;

	if (i == nb)
		ft_printtab(tab);
	if (i == nb)
		return (1);
	x = -1;
	y = -1;
	len = ft_strlen(tab[0]);
	tabf = ft_tabftetri2();
	while (++y < len)
	{
		while (++x < len)
			if (tabf[last[i]].f(tab, 'A' + i, x, y) == 1)
			{
				if (ft_backtrack(last, (i + 1), tab, nb) == 1)
					return (1);
				tabf[last[i]].c(tab, 46, x, y);
			}
		x = -1;
	}
	return (0);
}
