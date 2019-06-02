/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:59:27 by salibert          #+#    #+#             */
/*   Updated: 2016/11/28 11:28:37 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_t1(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x == 3 || y > 1))
			if (tab[x][y] == nb && tab[x][y + 1] == nb
					&& tab[x + 1][y + 1] == nb && tab[x][y + 2] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x == i || y > (i - 2)))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.'
					&& tab[x + 1][y + 1] == '.' && tab[x][y + 2] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x + 1][y + 1] = nb;
				tab[x][y + 2] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_t2(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x == 0 || y > 1))
			if (tab[x][y] == nb && tab[x][y + 1] == nb
					&& tab[x - 1][y + 1] == nb && tab[x][y + 2] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x == 0 || y > (i - 2)))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.'
					&& tab[x - 1][y + 1] == '.' && tab[x][y + 2] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x - 1][y + 1] = nb;
				tab[x][y + 2] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_t3(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(y == 3 || x == 0 || x == 3))
			if (tab[x][y] == nb && tab[x][y + 1] == nb
					&& tab[x + 1][y + 1] == nb && tab[x - 1][y + 1] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(y == i || x == 0 || x == i))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.'
					&& tab[x + 1][y + 1] == '.' && tab[x - 1][y + 1] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x + 1][y + 1] = nb;
				tab[x - 1][y + 1] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_t4(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x > 1 || y == 3))
			if (tab[x][y] == nb && tab[x + 1][y + 1] == nb
					&& tab[x + 1][y] == nb && tab[x + 2][y] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x > (i - 2) || y == i))
			if (tab[x][y] == '.' && tab[x + 1][y + 1] == '.'
					&& tab[x + 1][y] == '.' && tab[x + 2][y] == '.')
			{
				tab[x][y] = nb;
				tab[x + 1][y + 1] = nb;
				tab[x + 1][y] = nb;
				tab[x + 2][y] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_notfind(char **tab, int nb, int x, int y)
{
	nb = 0;
	x = 0;
	y = 0;
	if (tab)
		return (1);
	return (0);
}
