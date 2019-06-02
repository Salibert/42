/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <parvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:18:40 by salibert          #+#    #+#             */
/*   Updated: 2017/01/13 17:21:38 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void		ft_zero(t_fractol *p)
{
	p->n.re = 0;
	p->n.im = 0;
	p->old.re = 0;
	p->old.im = 0;
	p->tmp.re = 0;
	p->tmp.im = 0;
}

static void		ft_pw(t_fractol p, t_limit lim, t_pack p_b)
{
	p.i = 5;
	while (++p.i < (p_b.env.it_max))
	{
		p.old.re = fabs(p.n.re + p.n.re);
		p.old.im = fabs(p.n.im);
		p.n.re = p.tmp.re - p.tmp.im + p.c.re;
		p.n.im = p.old.re * p.old.im + p.c.im;
		p.tmp.re = p.n.re * p.n.re;
		p.tmp.im = p.n.im * p.n.im;
		if ((p.tmp.re + p.tmp.im) > 4)
			break ;
	}
	if (p.i == p_b.env.it_max)
		mlx_color(&p_b.env, lim.x, lim.y, (N));
	else
		mlx_color(&p_b.env, lim.x, lim.y, (((p.i + 100) * 4) + (800)));
}

void			*ft_boat(void *p_boat)
{
	t_pack		p_b;
	t_fractol	p;
	t_limit		lim;

	p_b = *(t_pack*)p_boat;
	lim = ft_limit_thread(p_b.nb_t);
	while (++lim.y < lim.max_y)
	{
		lim.x = lim.tmp_x;
		while (++lim.x < lim.max_x)
		{
			ft_zero(&p);
			p.c.re = ((double)(1.5 * (lim.x - p_b.env.h_x - p_b.env.o_m.nx))
					/ (double)(0.5 * p_b.env.z * X)) + p_b.env.o_z.im;
			p.c.im = ((double)(lim.y - p_b.env.h_y - p_b.env.o_m.ny)
				/ (double)(0.5 * p_b.env.z * Y)) + p_b.env.o_z.re;
			ft_pw(p, lim, p_b);
		}
	}
	return (NULL);
}
