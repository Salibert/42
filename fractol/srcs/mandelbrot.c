/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:19:13 by salibert          #+#    #+#             */
/*   Updated: 2017/01/13 17:03:53 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void		ft_zero(t_fractol *m)
{
	m->n.re = 0;
	m->n.im = 0;
	m->old.re = 0;
	m->old.im = 0;
	m->tmp.re = 0;
	m->tmp.im = 0;
}

static void		ft_pw(t_fractol m, t_limit lim, t_pack p_m)
{
	m.i = -1;
	while (++m.i < (p_m.env.it_max))
	{
		m.old.re = m.n.re + m.n.re;
		m.old.im = m.n.im;
		m.n.re = m.tmp.re - m.tmp.im + m.c.re;
		m.n.im = m.old.re * m.old.im + m.c.im;
		m.tmp.re = m.n.re * m.n.re;
		m.tmp.im = m.n.im * m.n.im;
		if ((m.tmp.re + m.tmp.im) > 4)
			break ;
	}
	if ((m.tmp.re + m.tmp.im) > 4)
		mlx_color(&p_m.env, lim.x, lim.y, (N) + (m.i * m.i));
	else if ((m.tmp.re + m.tmp.im) < 5)
		mlx_color(&p_m.env, lim.x, lim.y, (N));
}

void			*ft_mandelbrot(void *p_man)
{
	t_pack		p_m;
	t_fractol	m;
	t_limit		lim;

	p_m = *(t_pack*)p_man;
	lim = ft_limit_thread(p_m.nb_t);
	while (++lim.y < lim.max_y)
	{
		lim.x = lim.tmp_x;
		while (++lim.x < lim.max_x)
		{
			m.c.re = ((double)(1.5 * (lim.x - p_m.env.h_x - p_m.env.o_m.nx))
					/ (double)(0.5 * p_m.env.z * X)) + p_m.env.o_z.im;
			m.c.im = ((double)(lim.y - p_m.env.h_y - p_m.env.o_m.ny)
				/ (double)(0.5 * p_m.env.z * Y)) + p_m.env.o_z.re;
			ft_zero(&m);
			ft_pw(m, lim, p_m);
		}
	}
	return (NULL);
}
