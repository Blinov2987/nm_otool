/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:17:46 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/13 14:17:32 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_NM_H
# define NM_NM_H

# include "libft.h"
# include "errors.h"
# include "printf.h"
# include "args.h"
# include "headers.h"
# include "file_info.h"
# include "constants.h"
# include <sys/mman.h>

void		init_analytics(t_args *args);
int			walk_magic_64(t_file *file);
void		make_sort(t_file *file, t_args *args);
void		print_output(t_file *file, t_args *args);
void		print_simple(t_file *file, t_args *args);
void		print_simple_64(t_file *file, t_args *args);
void		print_file_name(t_file *file, t_args *args);
void		print_otool(t_file *file);
int			walk_magic_64(t_file *file);
int			see_in_segment_moment_64(void *start, size_t off_set, t_file *file);
char		*find_section_64(t_file *file, uint8_t index);
int			walk_magic(t_file *file);
int			see_in_segment_moment(void *start, size_t off_set, t_file *file);
char		*find_section(t_file *file, uint8_t index);
int			walk_magic_fat(t_file *file);
int			extrud_from_fat_64(t_file *file, int is_swap, size_t off_set);
void		swap_fat_header(t_fat_header *header);
uint32_t	swap_bytes(void *src, size_t n);

#endif
