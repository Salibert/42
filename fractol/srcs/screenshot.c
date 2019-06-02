/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:02:58 by salibert          #+#    #+#             */
/*   Updated: 2017/01/12 19:04:47 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void		ft_modif_screen(t_env *env)
{
	int			x;
	int			y;
	int			i;
	int			tmp;

	y = 0;
	i = -1;
	while (y < Y)
	{
		x = 0;
		while (x < X)
		{
			tmp = (x * (env->bpp / 8)) + (y * env->sizeline);
			env->screen[++i] = env->data[tmp + 2];
			env->screen[++i] = env->data[tmp + 1];
			env->screen[++i] = env->data[tmp];
			x++;
		}
		y++;
	}
}

void			ft_screenshot(t_env *env)
{
	int			fd;

	system("rm -fr ~/save.jpg");
	fd = open("save.jpg", O_WRONLY | O_CREAT);
	ft_modif_screen(env);
	ft_putstr_fd("P6 ", fd);
	ft_putnbr_fd(X, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(Y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(255, fd);
	ft_putstr_fd("\n", fd);
	write(fd, env->screen, X * Y * 3);
	close(fd);
	system("mv save.jpg ~/Desktop");
	ft_putendl("screenshot");
}

void			ft_norm(t_env *env)
{
	int			i;

	i = 0;
	while (env->s[i])
		ft_strdel(&env->s[i]);
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	ft_strdel(&env->name);
}
