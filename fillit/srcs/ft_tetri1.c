/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:23:03 by salibert          #+#    #+#             */
/*   Updated: 2016/11/27 14:36:45 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_carre(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x == 3 || y == 3))
			if (tab[x][y] == nb && tab[x + 1][y] == nb && tab[x][y + 1] == nb
					&& tab[x + 1][y + 1] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x == i || y == i))
			if (tab[x][y] == '.' && tab[x + 1][y] == '.' && tab[x][y + 1] == '.'
				&& tab[x + 1][y + 1] == '.')
			{
				tab[x][y] = nb;
				tab[x + 1][y] = nb;
				tab[x][y + 1] = nb;
				tab[x + 1][y + 1] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_ligne(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(x != 0))
			if (tab[x][y] == nb && tab[x + 1][y] == nb && tab[x + 2][y] == nb
					&& tab[x + 3][y] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x > (i - 3)))
			if (tab[x][y] == '.' && tab[x + 1][y] == '.' && tab[x + 2][y] == '.'
					&& tab[x + 3][y] == '.')
			{
				tab[x][y] = nb;
				tab[x + 1][y] = nb;
				tab[x + 2][y] = nb;
				tab[x + 3][y] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_colonne(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(y != 0))
			if (tab[x][y] == nb && tab[x][y + 1] == nb && tab[x][y + 2] == nb
					&& tab[x][y + 3] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(y > (i - 3)))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.' && tab[x][y + 2] == '.'
					&& tab[x][y + 3] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x][y + 2] = nb;
				tab[x][y + 3] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_l1(char **tab, int nb, int x, int y)
{
	int	i;

	if (nb == 35)
	{
		if (!(x == 3 || y > 1))
			if (tab[x][y] == nb && tab[x][y + 1] == nb && tab[x][y + 2] == nb
				&& tab[x + 1][y + 2] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x == i || y > (i - 2)))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.' && tab[x][y + 2] == '.'
				&& tab[x + 1][y + 2] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 2] = nb;
				tab[x + 1][y + 2] = nb;
				tab[x][y + 1] = nb;
				return (1);
			}
	}
	return (0);
}

int		ft_l2(char **tab, int nb, int x, int y)
{
	int i;

	if (nb == 35)
	{
		if (!(y > 1 || x == 0))
			if (tab[x][y] == nb && tab[x][y + 1] == nb && tab[x][y + 2] == nb
				&& tab[x - 1][y + 2] == nb)
				return (1);
	}
	else
	{
		i = ft_strlen(tab[x]) - 1;
		if (!(x == 0 || y > (i - 2)))
			if (tab[x][y] == '.' && tab[x][y + 1] == '.' && tab[x][y + 2] == '.'
				&& tab[x - 1][y + 2] == '.')
			{
				tab[x][y] = nb;
				tab[x][y + 1] = nb;
				tab[x][y + 2] = nb;
				tab[x - 1][y + 2] = nb;
				return (1);
			}
	}
	return (0);
}
