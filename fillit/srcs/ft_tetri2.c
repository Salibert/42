/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:46:52 by salibert          #+#    #+#             */
/*   Updated: 2016/11/27 11:58:04 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_l3(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(y > 1 || x == 3))
			if (tab[x][y] == nb && tab[x + 1][y] == nb && tab[x][y + 1] == nb
				&& tab[x][y + 2] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(y > (i - 2) || x == i))
			if (tab[x][y] == '.' && tab[x + 1][y] == '.' && tab[x][y + 1] == '.'
				&& tab[x][y + 2] == '.')
			{
				tab[x][y] = nb;
				tab[x + 1][y] = nb;
				tab[x][y + 1] = nb;
				tab[x][y + 2] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_l4(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x == 3 || y > 1))
			if (tab[x][y] == nb && tab[x + 1][y] == nb
					&& tab[x + 1][y + 1] == nb && tab[x + 1][y + 2] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x == i || y > (i - 2)))
			if (tab[x][y] == '.' && tab[x + 1][y] == '.'
					&& tab[x + 1][y + 1] == '.' && tab[x + 1][y + 2] == '.')
			{
				tab[x][y] = nb;
				tab[x + 1][y] = nb;
				tab[x + 1][y + 1] = nb;
				tab[x + 1][y + 2] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_l5(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x > 1 || y == 3))
			if (tab[x][y] == nb && tab[x][y + 1] == nb && tab[x + 1][y] == nb
					&& tab[x + 2][y] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x > (i - 2) || y == i))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.' && tab[x + 1][y] == '.'
				&& tab[x + 2][y] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x + 1][y] = nb;
				tab[x + 2][y] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_l6(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x > 1 || y == 3))
			if (tab[x][y] == nb && tab[x][y + 1] == nb
					&& tab[x + 1][y + 1] == nb && tab[x + 2][y + 1] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x > (i - 2) || y == i))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.'
					&& tab[x + 1][y + 1] == '.' && tab[x + 2][y + 1] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x + 1][y + 1] = nb;
				tab[x + 2][y + 1] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_l7(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x > 1 || y == 3))
			if (tab[x][y] == nb && tab[x + 1][y] == nb && tab[x + 2][y] == nb
					&& tab[x + 2][y + 1] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x > (i - 2) || y == i))
			if (tab[x][y] == '.' && tab[x + 1][y] == '.' && tab[x + 2][y] == '.'
				&& tab[x + 2][y + 1] == '.')
			{
				tab[x][y] = nb;
				tab[x + 1][y] = nb;
				tab[x + 2][y] = nb;
				tab[x + 2][y + 1] = nb;
				return (1);
			}
	}
	return (0);
}
