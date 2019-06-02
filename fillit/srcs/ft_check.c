/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:30:53 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/28 11:34:08 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int		ft_check_char(char *str)
{
	int		i;
	int		nb;
	int		p;
	int		n;

	i = 0;
	nb = 0;
	n = 0;
	p = 0;
	if (!str)
		return (ft_errors(-1));
	while (str[i])
	{
		if (str[i] == '.')
			p++;
		if (str[i] == '#')
			nb++;
		if (str[i] == '\n')
			n++;
		i++;
	}
	if (nb != 4 || n < 4 || p != 12)
		return (ft_errors(-1));
	return (1);
}

char	**ft_strtetri(char *str)
{
	int		i;
	int		x;
	int		y;
	char	**tab;

	i = 0;
	x = 0;
	y = -1;
	if (!(tab = (char**)malloc(sizeof(char*) * 5)))
		return (0);
	tab[4] = NULL;
	while (i < 4)
		tab[i++] = (char*)malloc(sizeof(char*) * 4);
	i = 0;
	while (++y < 4)
	{
		while (x < 4)
		{
			if (str[i] == '\n')
				i++;
			tab[x++][y] = str[i++];
		}
		x = 0;
	}
	return (tab);
}

int		ft_check_tab(char **tab, t_tt *tabf, int *last)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	y = -1;
	i = 0;
	while (++y < 4)
	{
		while (++x < 4)
			if (tab[x][y] == '#')
			{
				while (tabf[i].f(tab, 35, x, y) != 1 && i < 20)
					i++;
				if (i < 19)
					*last = i;
				if (i < 19)
					return (1);
				return (0);
			}
		x = -1;
	}
	return (0);
}

int		ft_check_tetri(char *str, int *last)
{
	char	**tab;
	t_tt	*tabf;

	tab = ft_strtetri(str);
	tabf = ft_tabftetri2();
	if (ft_check_tab(tab, tabf, last) == 1)
	{
		ft_freetab(&tab);
		return (1);
	}
	else
		return (ft_errors(-1));
}

int		ft_check(char *str, int *last)
{
	if (str[0] == '\n')
		return (ft_errors(-1));
	if (ft_check_char(str) == 0)
		return (0);
	if (ft_check_tetri(str, last) == 0)
		return (0);
	return (1);
}
