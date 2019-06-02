/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:58:46 by salibert          #+#    #+#             */
/*   Updated: 2018/10/19 08:35:04 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	ft_putstr(const char *s);
void	ft_putnbr_base(size_t nb, int base);
void	ft_print_addr_ptr(const void *addr);
void	*ft_memcpy (void *dest, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t n);
#endif
