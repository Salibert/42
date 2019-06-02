/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:16:48 by salibert          #+#    #+#             */
/*   Updated: 2017/01/13 17:48:20 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			ft_aff_help(int key, t_env *env)
{
	if (key == KEY_SPACEBAR && env->space == 0)
		env->space = 1;
	else if (key == KEY_SPACEBAR && env->space == 1)
		env->space = 0;
	if (key == KEY_H && env->h == 0)
		env->h = 1;
	else if (key == KEY_H && env->h == 1)
		env->h = 0;
	ft_help(env, env->mlx, env->win);
}

char			*ft_switch(char *s1, char *s2)
{
	char		*tmp;

	tmp = s1;
	s1 = s2;
	ft_strdel(&tmp);
	return (s1);
}

static void		ft_help_bis(t_env *env, void *mlx, void *win)
{
	char		*tmp;

	mlx_put_image_to_window(mlx, win, env->img, 0, 0);
	tmp = ft_ditoa(env->z, 1);
	mlx_string_put(mlx, win, 5, 5, B, env->s[6]);
	mlx_string_put(mlx, win, 5 + ft_strlen(env->s[6]) * 10, 5, B, tmp);
	tmp = ft_switch(tmp, ft_itoa(env->it_max));
	mlx_string_put(mlx, win, 5, 22, B, env->s[7]);
	mlx_string_put(mlx, win, 5 + ft_strlen(env->s[7]) * 10, 22, B, tmp);
	mlx_string_put(mlx, win, 5, 42, B, env->s[8]);
	if (env->space == 1)
		mlx_string_put(mlx, win, 5 + ft_strlen(env->s[8]) * 10
				, 42, B, env->s[9]);
	else if (env->space == 0)
		mlx_string_put(mlx, win, 5 + ft_strlen(env->s[8]) * 10
				, 42, B, env->s[10]);
	mlx_string_put(mlx, win, 5, 62, B, env->s[0]);
	ft_strdel(&tmp);
}

void			ft_help(t_env *env, void *mlx, void *win)
{
	if (env->h == 0)
		ft_help_bis(env, mlx, win);
	else if (env->h == 1)
	{
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		mlx_string_put(mlx, win, 5, 5, B, env->s[1]);
		mlx_string_put(mlx, win, 5, 22, B, env->s[2]);
		mlx_string_put(mlx, win, 5, 42, B, env->s[3]);
		mlx_string_put(mlx, win, 5, 57, B, env->s[4]);
		mlx_string_put(mlx, win, 5, 74, B, env->s[5]);
	}
}

void			init_help(t_env *env)
{
	env->h = 0;
	if (!(env->s = (char**)malloc(sizeof(char*) * 12)))
		error("malloc en->s in affichage.c");
	env->s[0] = ft_strdup("| Press 'H' for list help");
	env->s[1] = ft_strdup("| Mouse Click LEFT move the map |");
	env->s[2] = ft_strdup("| Mouse Click RIGHT zoom & move |");
	env->s[3] = ft_strdup("| Scroll Back Dezoom            |");
	env->s[4] = ft_strdup("| Barre SPACE Pause             |");
	env->s[5] = ft_strdup("| Q & W switch fractol          |");
	env->s[6] = ft_strdup("| ZOOM x ");
	env->s[7] = ft_strdup("| IT_MAX : ");
	env->s[8] = ft_strdup("| SPACE: ");
	env->s[9] = ft_strdup("ON");
	env->s[10] = ft_strdup("OFF");
	env->s[11] = NULL;
}
