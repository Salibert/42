/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctetri1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:21:18 by salibert          #+#    #+#             */
/*   Updated: 2016/11/25 13:21:23 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_ccarre(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x + 1][y] = nb;
	tab[x][y + 1] = nb;
	tab[x + 1][y + 1] = nb;
	return (1);
}

int		ft_cligne(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x + 1][y] = nb;
	tab[x + 2][y] = nb;
	tab[x + 3][y] = nb;
	return (1);
}

int		ft_ccolonne(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x][y + 2] = nb;
	tab[x][y + 3] = nb;
	return (1);
}

int		ft_cl1(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 2] = nb;
	tab[x + 1][y + 2] = nb;
	tab[x][y + 1] = nb;
	return (1);
}

int		ft_cl2(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x][y + 2] = nb;
	tab[x - 1][y + 2] = nb;
	return (1);
}
