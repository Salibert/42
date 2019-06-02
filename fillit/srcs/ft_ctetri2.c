/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctetri2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:21:32 by salibert          #+#    #+#             */
/*   Updated: 2016/11/25 13:21:35 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_cl3(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x + 1][y] = nb;
	tab[x][y + 1] = nb;
	tab[x][y + 2] = nb;
	return (1);
}

int		ft_cl4(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x + 1][y] = nb;
	tab[x + 1][y + 1] = nb;
	tab[x + 1][y + 2] = nb;
	return (1);
}

int		ft_cl5(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x + 1][y] = nb;
	tab[x + 2][y] = nb;
	return (1);
}

int		ft_cl6(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x][y + 1] = nb;
	tab[x + 1][y + 1] = nb;
	tab[x + 2][y + 1] = nb;
	return (1);
}

int		ft_cl7(char **tab, int nb, int x, int y)
{
	tab[x][y] = nb;
	tab[x + 1][y] = nb;
	tab[x + 2][y] = nb;
	tab[x + 2][y + 1] = nb;
	return (1);
}
