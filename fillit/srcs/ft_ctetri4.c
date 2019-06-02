/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctetri4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:22:01 by salibert          #+#    #+#             */
/*   Updated: 2016/11/25 13:22:04 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_ct1(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x + 1][y + 1] = nb;
	tab[x][y + 2] = nb;
	return (1);
}

int		ft_ct2(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x - 1][y + 1] = nb;
	tab[x][y + 2] = nb;
	return (1);
}

int		ft_ct3(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x + 1][y + 1] = nb;
	tab[x - 1][y + 1] = nb;
	return (1);
}

int		ft_ct4(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x + 1][y + 1] = nb;
	tab[x + 1][y] = nb;
	tab[x + 2][y] = nb;
	return (1);
}
