/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:53:12 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/05/07 17:53:27 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define N 128
# define M 1024
# define IS_TINY(x) (x >= 1 && x <= N)
# define IS_SMALL(x) (x > N && x < M)
# define IS_LARGE(x) (x >= M)

# include <stdlib.h>
# include <sys/mman.h>
# include "ft_printf/ft_printf_header.h"
# include "libft/libft.h"
# include "struct.h"

/*
** free.c
*/
int		free_block(t_block *blocks[], t_type type, void *ptr);
void	free_page(t_block *blocks[], t_type type);
void	free_page_help(t_block *blocks[], t_block *block, t_type type,
			t_block **prev);

/*
** print.c
*/
void	print(char *mame, t_block *block);
void	print_double_free(void);
void	print_bus_error(void);

/*
** get.c
*/
void	*get_new_page(t_block *blocks[], t_type type, size_t size);
void	*get_free_space(t_block *blocks[3], t_type type, size_t size);
void	*get_free_space_on_page(t_block *block, size_t size, int num);
t_block	*get_block(t_block *blocks[], void *ptr);
t_type	get_type(size_t size);

/*
** expose.h
*/
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);
void	show_alloc_mem();

/*
** util.c
*/
void	*allocate(t_block *blocks[3], size_t size, t_type type);
void	*reallocate(t_block *block, size_t size);
t_block *new_block_realloc(t_block *start, t_block *block,
			size_t space, size_t size);
t_block	*new_block_get_free_space_on_page(t_block *block, t_block *start,
			size_t size, size_t space);
int		is_free_space(t_block *blocks[], t_type type,
			void *ptr, size_t size);

#endif
