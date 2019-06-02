/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 09:57:28 by salibert          #+#    #+#             */
/*   Updated: 2017/01/14 12:18:13 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "macro_key_mlx.h"
# include <math.h>
# include <pthread.h>
# define JULIA "julia"
# define MANDEL "mandelbrot"
# define BOAT "burningship"
# define X 1600
# define Y 800
# define MAX_IT 200
# define NB_THREAD 16
# define N 0x00000000
# define B 0x00FFFFFF

typedef struct		s_point
{
	int				nx;
	int				ny;
}					t_point;

typedef struct		s_double
{
	double			re;
	double			im;
}					t_double;

typedef struct		s_fractol
{
	t_double		n;
	t_double		old;
	t_double		c;
	int				i;
	t_double		tmp;
}					t_fractol;

typedef struct		s_limit
{
	int				x;
	int				y;
	int				max_x;
	int				max_y;
	int				tmp_x;
}					t_limit;

typedef struct		s_env
{
	char			*name;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	double			z;
	int				h_x;
	int				h_y;
	t_double		o_z;
	t_point			o_m;
	int				it_max;
	int				nb_frac;
	t_double		cn;
	t_point			p;
	int				space;
	int				shot;
	unsigned char	*screen;
	int				double_it;
	char			**s;
	int				h;
	int				my;
	int				mx;
}					t_env;

typedef struct		s_pack
{
	t_env			env;
	double			cnre;
	double			cnim;
	int				nb_t;
}					t_pack;

void				ft_reset(t_env *env);
void				zoom_frac(int x, int y, t_env *env);
int					ft_move(int keycode, t_env *env);
void				ft_norm(t_env *env);
void				ft_aff_help(int key, t_env *env);
void				ft_it_put(t_env *env, int etat);
void				init_help(t_env *env);
void				ft_help(t_env *env, void *mlx, void *win);
void				ft_screenshot(t_env *env);
void				init_env(t_env *env, char *name, int etat);
int					error(char *msg_error);
void				mlx_color(t_env *env, int x, int y, int int_color);
void				*ft_julia(void *p_julia);
int					ft_mouse(int x, int y, t_env *env);
int					touch(int keycode, t_env *env);
void				*ft_mandelbrot(void *p_man);
void				*ft_boat(void *p_boat);
void				init_thread1(t_env *env);
void				init_thread2(t_env *env);
void				init_thread3(t_env *env);
void				ft_screenshot(t_env *env);
t_limit				ft_limit_thread(int nb);
void				nb_frac(t_env *env, int etat);
int					ft_zoom(int button, int x, int y, t_env *env);
#endif
