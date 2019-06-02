/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:59:42 by salibert          #+#    #+#             */
/*   Updated: 2018/10/22 11:16:59 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include "../libft/libft.h"
# include <sys/mman.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# define TRUE 1
# define FALSE 0
# define SIZE_MAX_TINY 1200
# define SIZE_MAX_SMALL 127000
# define SIZE_TINY 450
# define SIZE_SMALL 3600
# define TINY_QUANTIUM 16
# define SMALL_QUANTIUM 512
# define LARGE_QUANTIUM 4096
# define LOCK(mtx) pthread_mutex_lock(mtx)
# define UNLOCK(mtx) pthread_mutex_unlock(mtx)
# define OFFSET_PTR g_malloc.offset_ptr

enum { TINY = 0, SMALL = 1, LARGE = 2 };

typedef unsigned char	t_bool;

typedef struct			s_list
{
	struct s_list		*next;
	t_bool				is_free;
	unsigned int		size_block;
}						t_list;

typedef struct			s_zone
{
	struct s_zone		*next;
	size_t				not_allocated;
	size_t				size_z;
	t_list				*begin_list;
	int					type;
}						t_zone;

typedef struct			s_malloc
{
	t_bool				initial_malloc;
	int					page_size;
	int					offset_ptr;
	t_zone				*types[3];
	size_t				size[2];
}						t_malloc;

typedef struct			s_mtx_malloc
{
	pthread_mutex_t		g_malloc;
}						t_mtx_malloc;

void					init_malloc(void);
void					free(void *ptr);
void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					show_alloc_mem();
void					deframenter(t_list **previous, t_list **current);
void					ft_delete_zone(t_zone **alst, t_zone *del);
void					ft_push_back_zone(t_zone **alst, t_zone *n);
size_t					cal_q_size(size_t size, int type, int offset);
size_t					get_type_zone(size_t size);
size_t					get_size_z_by_type(size_t size, int type);

#endif
