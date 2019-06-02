/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:28:52 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/26 17:54:25 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_printtab(char **tab)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (tab[x][y])
	{
		while (tab[x])
		{
			ft_putchar(tab[x][y]);
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

void	ft_printtab_fd(char **tab, int fd)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (tab[x][y])
	{
		while (tab[x])
		{
			write(fd, &tab[x][y], 1);
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}
