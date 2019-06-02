/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:02:05 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/28 11:22:47 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_tetriminos
{
	int			(*f)(char **tab, int nb, int y, int x);
	int			(*c)(char **tab, int nb, int y, int x);
}				t_tt;

int				ft_errors(int n);
int				ft_read(char *file, char c, int nb);
void			ft_tabftetri1(t_tt *tabftetri);
t_tt			*ft_tabftetri2(void);
int				ft_check(char *str, int *last);
int				ft_check_char(char *str);
int				ft_check_tetri(char *str, int *last);
int				ft_check_tab(char **tab, t_tt *tabf, int *last);
char			**ft_strtetri(char *str);
int				ft_backtrack(int *last, int i, char **tab, int nb);
char			**ft_create_finaltab(int nb);
int				ft_carre(char **tab, int nb, int y, int x);
int				ft_ligne(char **tab, int nb, int y, int x);
int				ft_colonne(char **tab, int nb, int y, int x);
void			ft_printtab(char **tab);
char			**ft_realloc(char **tab);
int				ft_l1(char **tab, int nb, int y, int x);
int				ft_l2(char **tab, int nb, int y, int x);
int				ft_l3(char **tab, int nb, int y, int x);
int				ft_l4(char **tab, int nb, int y, int x);
int				ft_l5(char **tab, int nb, int y, int x);
int				ft_l6(char **tab, int nb, int y, int x);
int				ft_l7(char **tab, int nb, int y, int x);
int				ft_l8(char **tab, int nb, int y, int x);
int				ft_z1(char **tab, int nb, int y, int x);
int				ft_z2(char **tab, int nb, int y, int x);
int				ft_z3(char **tab, int nb, int y, int x);
int				ft_z4(char **tab, int nb, int y, int x);
int				ft_t1(char **tab, int nb, int y, int x);
int				ft_t2(char **tab, int nb, int y, int x);
int				ft_t3(char **tab, int nb, int y, int x);
int				ft_t4(char **tab, int nb, int y, int x);
int				ft_ccarre(char **tab, int nb, int y, int x);
int				ft_cligne(char **tab, int nb, int y, int x);
int				ft_ccolonne(char **tab, int nb, int y, int x);
void			ft_cprinttab(char **tab);
int				ft_cl1(char **tab, int nb, int y, int x);
int				ft_cl2(char **tab, int nb, int y, int x);
int				ft_cl3(char **tab, int nb, int y, int x);
int				ft_cl4(char **tab, int nb, int y, int x);
int				ft_cl5(char **tab, int nb, int y, int x);
int				ft_cl6(char **tab, int nb, int y, int x);
int				ft_cl7(char **tab, int nb, int y, int x);
int				ft_cl8(char **tab, int nb, int y, int x);
int				ft_cz1(char **tab, int nb, int y, int x);
int				ft_cz2(char **tab, int nb, int y, int x);
int				ft_cz3(char **tab, int nb, int y, int x);
int				ft_cz4(char **tab, int nb, int y, int x);
int				ft_ct1(char **tab, int nb, int y, int x);
int				ft_ct2(char **tab, int nb, int y, int x);
int				ft_ct3(char **tab, int nb, int y, int x);
int				ft_ct4(char **tab, int nb, int y, int x);
int				ft_notfind(char **tab, int nb, int y, int x);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			ft_freetab(char ***tab);
void			ft_strdel(char **as);
void			ft_bzero(void *s, size_t n);
void			ft_printtab_fd(char **tab, int fd);
void			ft_stock(char **tab);

#endif
