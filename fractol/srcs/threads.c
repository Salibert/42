/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 10:36:01 by salibert          #+#    #+#             */
/*   Updated: 2017/01/14 12:14:40 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_limit			ft_limit_thread(int nb)
{
	t_limit		lim;
	int			modulo_y;
	int			modulo_x;

	modulo_x = nb % 4;
	modulo_y = (nb % 16) / 4;
	lim.x = 0;
	lim.tmp_x = ((X * modulo_x) / 4) - 1;
	lim.y = (Y * modulo_y / 4) - 1;
	lim.max_x = (X * (modulo_x + 1)) / 4;
	lim.max_y = (Y * (modulo_y + 1)) / 4;
	return (lim);
}

void			ft_it_put(t_env *env, int etat)
{
	if (etat == 0)
	{
		if (env->shot == 1)
			env->it_max = 10000;
		else
		{
			if (env->z < 10)
				env->it_max = ft_trim(200, 400, (int)(MAX_IT * env->z));
			else
				env->it_max = ft_trim(200, 800, (int)(MAX_IT * env->z));
		}
	}
	else if (etat == 1)
		if (env->shot == 0)
			ft_help(env, env->mlx, env->win);
}

void			init_thread1(t_env *env)
{
	pthread_t	*t;
	t_pack		*p_julia;
	int			nb_t;

	nb_t = -1;
	ft_it_put(env, 0);
	if (!(p_julia = (t_pack*)malloc(sizeof(t_pack) * NB_THREAD)))
		error("malloc p_julia in thrad.c");
	if (!(t = (pthread_t*)malloc(sizeof(pthread_t) * NB_THREAD)))
		error("malloc pthread_t1 in thread.c");
	while (++nb_t < NB_THREAD)
	{
		p_julia[nb_t].env = *env;
		p_julia[nb_t].cnre = env->cn.re;
		p_julia[nb_t].cnim = env->cn.im;
		p_julia[nb_t].nb_t = nb_t;
		pthread_create(&t[nb_t], NULL, &ft_julia, &p_julia[nb_t]);
	}
	nb_t = -1;
	while (++nb_t < NB_THREAD)
		pthread_join(t[nb_t], NULL);
	ft_it_put(env, 1);
	ft_memdel((void**)&t);
	ft_memdel((void**)&p_julia);
}

void			init_thread2(t_env *env)
{
	pthread_t	*t;
	t_pack		*p_man;
	int			nb_t;

	nb_t = -1;
	ft_it_put(env, 0);
	if (!(p_man = (t_pack*)malloc(sizeof(t_pack) * NB_THREAD)))
		error("malloc p_manin thread.c");
	if (!(t = (pthread_t*)malloc(sizeof(pthread_t) * NB_THREAD)))
		error("malloc pthread_t2 in thread.c");
	while (++nb_t < NB_THREAD)
	{
		p_man[nb_t].env = *env;
		p_man[nb_t].cnre = env->cn.re;
		p_man[nb_t].cnim = env->cn.im;
		p_man[nb_t].nb_t = nb_t;
		pthread_create(&t[nb_t], NULL, &ft_mandelbrot, &p_man[nb_t]);
	}
	nb_t = -1;
	while (++nb_t < NB_THREAD)
		pthread_join(t[nb_t], NULL);
	ft_it_put(env, 1);
	ft_memdel((void**)&t);
	ft_memdel((void**)&p_man);
}

void			init_thread3(t_env *env)
{
	pthread_t	*t;
	t_pack		*p_boat;
	int			nb_t;

	nb_t = -1;
	ft_it_put(env, 0);
	if (!(p_boat = (t_pack*)malloc(sizeof(t_pack) * NB_THREAD)))
		error("malloc p_manin thread.c");
	if (!(t = (pthread_t*)malloc(sizeof(pthread_t) * NB_THREAD)))
		error("malloc pthread_t2 in thread.c");
	while (++nb_t < NB_THREAD)
	{
		p_boat[nb_t].env = *env;
		p_boat[nb_t].cnre = env->cn.re;
		p_boat[nb_t].cnim = env->cn.im;
		p_boat[nb_t].nb_t = nb_t;
		pthread_create(&t[nb_t], NULL, &ft_boat, &p_boat[nb_t]);
	}
	nb_t = -1;
	while (++nb_t < NB_THREAD)
		pthread_join(t[nb_t], NULL);
	ft_it_put(env, 1);
	ft_memdel((void**)&t);
	ft_memdel((void**)&p_boat);
}
