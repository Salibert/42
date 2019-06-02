/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:06:15 by salibert          #+#    #+#             */
/*   Updated: 2016/12/10 15:40:31 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_line(char **all, char **line)
{
	char	*tmp;
	int		n;

	if (*all && ft_strcmp(*all, "") && (tmp = ft_strchr(*all, END)))
	{
		n = tmp - *all;
		tmp = ft_strdup(tmp);
		*line = ft_strsub(*all, 0, n);
		ft_strdel(all);
		*all = ft_strdup(tmp + 1);
		ft_strdel(&tmp);
		return (1);
	}
	else if (*all && ft_strcmp(*all, "") && !ft_strchr(*all, END))
	{
		*line = ft_strdup(*all);
		ft_strdel(all);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *all = NULL;
	char		buf[BUFF_SIZE + 1];
	int			nb;

	if (read(fd, &buf, 0) < 0)
		return (-1);
	if (!all && (nb = read(fd, &buf, BUFF_SIZE)))
	{
		buf[nb] = '\0';
		all = ft_strdup(buf);
		ft_bzero(buf, nb);
	}
	while (all && !ft_strchr(all, END) && (nb = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[nb] = '\0';
		all = ft_strjoinf(all, buf, 'L');
		ft_bzero(buf, nb);
	}
	if (all && ft_line(&all, line) == 1)
		return (1);
	return (0);
}
