/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:32:43 by salibert          #+#    #+#             */
/*   Updated: 2017/01/13 17:15:48 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			nb_frac(t_env *env, int etat)
{
	if (etat == 0)
	{
		if (!ft_strcmp(env->name, JULIA) || ft_atoi(env->name) == 1)
			env->nb_frac = 1;
		if (!ft_strcmp(env->name, MANDEL) || ft_atoi(env->name) == 2)
			env->nb_frac = 2;
		if (!ft_strcmp(env->name, BOAT) || ft_atoi(env->name) == 3)
			env->nb_frac = 3;
		if (env->nb_frac == 0)
			error("usage");
	}
	else if (etat == 1)
	{
		if (env->nb_frac == 1)
			init_thread1(env);
		if (env->nb_frac == 2)
			init_thread2(env);
		if (env->nb_frac == 3)
			init_thread3(env);
	}
}

int				error(char *mgs_error)
{
	if (!ft_strcmp("usage", mgs_error))
	{
		ft_putendl_fd("usage: ./fractol [name or nb]", 2);
		ft_putendl_fd("1 -- julia", 2);
		ft_putendl_fd("2 -- mandelbrot", 2);
		ft_putendl_fd("3 -- burningship", 2);
	}
	else if (mgs_error)
	{
		ft_putstr_fd(" error :", 2);
		ft_putendl_fd(mgs_error, 2);
	}
	else
		ft_putendl_fd("error", 2);
	exit(-1);
	return (0);
}

void			init_env(t_env *env, char *name, int etat)
{
	if (etat == 0)
	{
		if (!(env->screen =
				(unsigned char*)malloc(sizeof(unsigned char) * (3 * X * Y))))
			error("malloc screen");
		init_help(env);
		env->nb_frac = 0;
		env->name = name;
		nb_frac(env, 0);
		env->mlx = mlx_init();
		env->win = mlx_new_window(env->mlx, X, Y, "Fractol");
		env->img = mlx_new_image(env->mlx, X, Y);
		env->data = mlx_get_data_addr(env->img, &env->bpp,
				&env->sizeline, &env->endian);
		env->space = 0;
	}
	ft_reset(env);
}

int				main(int ac, char **av)
{
	t_env		*env;
	char		*name;

	if (ac != 2)
		error("usage");
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		error("malloc t_env");
	name = ft_strdup(av[1]);
	init_env(env, name, 0);
	nb_frac(env, 1);
	mlx_key_hook(env->win, touch, env);
	mlx_hook(env->win, 2, (1l << 0), ft_move, env);
	mlx_mouse_hook(env->win, ft_zoom, env);
	mlx_hook(env->win, 6, (1L << 6), ft_mouse, env);
	ft_it_put(env, 1);
	mlx_loop(env->mlx);
	return (0);
}
