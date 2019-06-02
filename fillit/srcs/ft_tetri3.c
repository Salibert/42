/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:14:35 by salibert          #+#    #+#             */
/*   Updated: 2016/11/27 11:43:26 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_l8(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(y == 3 || x < 2))
			if (tab[x][y] == nb && tab[x][y + 1] == nb
					&& tab[x - 1][y + 1] == nb && tab[x - 2][y + 1] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(y == i || x < 2))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.'
					&& tab[x - 1][y + 1] == '.' && tab[x - 2][y + 1] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x - 1][y + 1] = nb;
				tab[x - 2][y + 1] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_z1(char **tab, int nb, int x, int y)
{
	int	i;

	if (nb == 35)
	{
		if (!(y == 3 || x > 1))
			if (tab[x][y] == nb && tab[x + 1][y] == nb
					&& tab[x + 1][y + 1] == nb && tab[x + 2][y + 1] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(y == i || x > i - 2))
			if (tab[x][y] == '.' && tab[x + 1][y] == '.'
					&& tab[x + 1][y + 1] == '.' && tab[x + 2][y + 1] == '.')
			{
				tab[x][y] = nb;
				tab[x + 1][y] = nb;
				tab[x + 1][y + 1] = nb;
				tab[x + 2][y + 1] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_z2(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(y == 3 || x == 0 || x == 3))
			if (tab[x][y] == nb && tab[x + 1][y] == nb
					&& tab[x][y + 1] == nb && tab[x - 1][y + 1] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(y == i || x == 0 || x == i))
			if (tab[x][y] == '.' && tab[x + 1][y] == '.'
					&& tab[x][y + 1] == '.' && tab[x - 1][y + 1] == '.')
			{
				tab[x][y] = nb;
				tab[x + 1][y] = nb;
				tab[x][y + 1] = nb;
				tab[x - 1][y + 1] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_z3(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(y > 1 || x == 3))
			if (tab[x][y] == nb && tab[x][y + 1] == nb
					&& tab[x + 1][y + 1] == nb && tab[x + 1][y + 2] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(y > (i - 2) || x == i))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.'
					&& tab[x + 1][y + 1] == '.' && tab[x + 1][y + 2] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x + 1][y + 1] = nb;
				tab[x + 1][y + 2] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_z4(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x == 0 || y > 1))
			if (tab[x][y] == nb && tab[x][y + 1] == nb
					&& tab[x - 1][y + 1] == nb && tab[x - 1][y + 2] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x == 0 || y > (i - 2)))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.'
					&& tab[x - 1][y + 1] == '.' && tab[x - 1][y + 2] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x - 1][y + 1] = nb;
				tab[x - 1][y + 2] = nb;
				return (1);
			}
	}
	return (0);
}
