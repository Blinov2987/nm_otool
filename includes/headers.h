/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:13:16 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/12 10:15:45 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_HEADERS_H
# define NM_HEADERS_H

# include <mach-o/arch.h>
# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include <ar.h>

typedef struct mach_header			t_mach_header;
typedef struct mach_header_64		t_mach_header_64;
typedef struct fat_header			t_fat_header;
typedef struct fat_arch				t_fat_arch;
typedef struct fat_arch_64			t_fat_arch_64;
typedef struct load_command			t_load_command;
typedef struct segment_command		t_segment_command;
typedef struct segment_command_64	t_segment_command_64;
typedef struct section				t_section;
typedef struct section_64			t_section_64;
typedef struct symtab_command		t_symtab_command;
typedef struct nlist				t_nlist;
typedef struct nlist_64				t_nlist_64;

#endif
