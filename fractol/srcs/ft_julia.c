/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:24:08 by salibert          #+#    #+#             */
/*   Updated: 2017/01/13 17:05:56 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int		modif_julia(t_fractol *j, t_pack p_j)
{
	if (j->c.re != (-0.7))
	{
		j->c.re = -0.7;
		j->c.im = 0.27015;
	}
	j->old.re = j->n.re;
	j->old.im = j->n.im;
	j->n.re = j->tmp.re - j->tmp.im + (j->c.re + p_j.cnre);
	j->n.im = (j->old.re + j->old.re) * j->old.im + (j->c.im + p_j.cnim);
	j->tmp.re = j->n.re * j->n.re;
	j->tmp.im = j->n.im * j->n.im;
	if ((j->tmp.re + j->tmp.im) > 4)
		return (0);
	return (1);
}

void			*ft_julia(void *p_julia)
{
	t_pack		p_j;
	t_fractol	j;
	t_limit		l;

	p_j = *((t_pack*)p_julia);
	l = ft_limit_thread(p_j.nb_t);
	while (++l.y < l.max_y)
	{
		l.x = l.tmp_x;
		while (++l.x < l.max_x)
		{
			j.n.re = ((double)(1.5 * (l.x - p_j.env.h_x - p_j.env.o_m.nx))
					/ (double)(0.5 * p_j.env.z * X)) + p_j.env.o_z.im;
			j.n.im = ((double)((l.y - p_j.env.h_y - p_j.env.o_m.ny))
					/ (double)(0.5 * p_j.env.z * Y)) + p_j.env.o_z.re;
			j.tmp.re = j.n.re * j.n.re;
			j.tmp.im = j.n.im * j.n.im;
			j.i = 0;
			while (++j.i < (p_j.env.it_max))
				if (!(modif_julia(&j, p_j)))
					break ;
			mlx_color(&p_j.env, l.x, l.y, (j.i > 2 ? (B / (j.i + 50)) : (N)));
		}
	}
	return (NULL);
}
