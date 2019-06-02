/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:48:44 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/27 16:29:31 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		*ft_create_last(int last[27], int nb)
{
	int		i;
	int		*new;

	i = 0;
	if (!(new = (int *)malloc(sizeof(*new) * nb + 1)))
		return (0);
	while (i < nb)
	{
		new[i] = last[i];
		i++;
	}
	return (new);
}

int		ft_read(char *file, char c, int nb)
{
	int		fd;
	char	buf[22];
	int		last[27];
	char	**tab;

	if ((fd = open(file, O_DIRECTORY)) == -1)
	{
		if ((fd = open(file, O_RDONLY)) == -1)
			return (-1);
		while (read(fd, &buf, 21) != 0)
		{
			buf[21] = '\0';
			c = buf[20];
			if (ft_check(buf, &last[nb++]) == 0)
				return (0);
			ft_memset(buf, '\0', 22);
		}
	}
	if (nb == 0 || c == '\n')
		return (ft_errors(-1));
	tab = ft_create_finaltab(nb);
	while (ft_backtrack(ft_create_last(last, nb), 0, tab, nb) == 0)
		tab = ft_realloc(tab);
	return (0);
}
