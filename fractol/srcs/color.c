/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:43:27 by salibert          #+#    #+#             */
/*   Updated: 2017/01/10 13:39:53 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		mlx_color(t_env *env, int x, int y, int int_color)
{
	char	*color;
	int		tmp;

	int_color = mlx_get_color_value(env->mlx, int_color);
	color = (char*)&int_color;
	tmp = (x * (env->bpp / 8)) + (y * env->sizeline);
	env->data[tmp] = color[0];
	env->data[tmp + 1] = color[1];
	env->data[tmp + 2] = color[2];
}
