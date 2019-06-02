/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:05:25 by salibert          #+#    #+#             */
/*   Updated: 2017/01/13 18:20:29 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void		ft_switch_frac(int keycode, t_env *env)
{
	if (keycode == KEY_W && env->space == 1)
	{
		if (env->nb_frac < 3)
			env->nb_frac += 1;
		else if (env->nb_frac == 3)
			env->nb_frac = 1;
	}
	if (keycode == KEY_Q && env->space == 1)
	{
		if (env->nb_frac > 1)
			env->nb_frac -= 1;
		else if (env->nb_frac == 1)
			env->nb_frac = 3;
	}
	init_env(env, NULL, 1);
	nb_frac(env, 1);
}

int				touch(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		ft_norm(env);
		ft_memdel((void**)env);
		exit(0);
	}
	if (keycode == KEY_SPACEBAR || keycode == KEY_H)
		ft_aff_help(keycode, env);
	if (keycode == KEY_S && env->space == 1)
	{
		env->shot = 1;
		nb_frac(env, 1);
		ft_screenshot(env);
		env->shot = 0;
	}
	if (keycode == KEY_Q || keycode == KEY_R || keycode == KEY_W)
		ft_switch_frac(keycode, env);
	return (0);
}

int				ft_mouse(int x, int y, t_env *env)
{
	if (env->space == 0 && env->nb_frac == 1)
	{
		x -= env->h_x;
		y -= env->h_y;
		env->cn.re = 0.0009 * x;
		env->cn.im = 0.0009 * y;
		nb_frac(env, 1);
	}
	return (0);
}

void			move_frac(int x, int y, t_env *env)
{
	if (x <= env->h_x)
		env->o_m.nx += env->h_x - x;
	else if (x > env->h_x)
		env->o_m.nx += -1 * (x - env->h_x);
	if (y <= env->h_y)
		env->o_m.ny += env->h_y - y;
	else if (y > env->h_y)
		env->o_m.ny += -1 * (y - env->h_y);
}

int				ft_zoom(int button, int x, int y, t_env *env)
{
	if (x < 0 || y < 0)
		return (0);
	if (button == 1)
		move_frac(x, y, env);
	if (button == 5)
	{
		env->z += (0.5);
		zoom_frac(x, y, env);
	}
	if (button == 4 && env->z > 1)
	{
		if (env->z > 50)
			env->z -= (10);
		else if (env->z > 2)
			env->z -= (2);
		zoom_frac(x, y, env);
	}
	nb_frac(env, 1);
	return (0);
}
