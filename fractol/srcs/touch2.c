/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:05:07 by salibert          #+#    #+#             */
/*   Updated: 2017/01/13 18:20:27 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_move(int keycode, t_env *env)
{
	if (keycode == KEY_UP)
		env->o_m.ny -= 10;
	if (keycode == KEY_DOWN)
		env->o_m.ny += 10;
	if (keycode == KEY_LEFT)
		env->o_m.nx -= 10;
	if (keycode == KEY_RIGHT)
		env->o_m.nx += 10;
	nb_frac(env, 1);
	return (0);
}

void	zoom_frac(int x, int y, t_env *env)
{
	env->o_z.im -= (env->h_x - x) * 0.0005 / env->z;
	env->o_z.re -= (env->h_y - y) * 0.0005 / env->z;
}

void	ft_reset(t_env *env)
{
	env->shot = 0;
	env->o_z.re = 0;
	env->o_z.im = 0;
	env->o_m.nx = 0;
	env->o_m.ny = 0;
	env->z = 0.6;
	env->double_it = 1;
	env->h_x = X / 2;
	env->h_y = Y / 2;
}
