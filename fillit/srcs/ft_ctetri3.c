/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctetri3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:21:50 by salibert          #+#    #+#             */
/*   Updated: 2016/11/25 13:21:51 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_cl8(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x - 1][y + 1] = nb;
	tab[x - 2][y + 1] = nb;
	return (1);
}

int		ft_cz1(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x + 1][y] = nb;
	tab[x + 1][y + 1] = nb;
	tab[x + 2][y + 1] = nb;
	return (1);
}

int		ft_cz2(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x + 1][y] = nb;
	tab[x][y + 1] = nb;
	tab[x - 1][y + 1] = nb;
	return (1);
}

int		ft_cz3(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x + 1][y + 1] = nb;
	tab[x + 1][y + 2] = nb;
	return (1);
}

int		ft_cz4(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x - 1][y + 1] = nb;
	tab[x - 1][y + 2] = nb;
	return (1);
}
