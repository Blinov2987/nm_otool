/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:13:16 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/01 18:54:49 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_HEADERS_H
#define NM_HEADERS_H

#include <mach-o/arch.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>

typedef struct mach_header t_mach_header;
typedef struct mach_header_64 t_mach_header_64;
typedef struct fat_header t_fat_header;
typedef struct fat_arch t_fat_arch;
typedef struct fat_arch_64 t_fat_arch_64;
typedef struct load_command t_load_command;
typedef struct segment_command t_segment_command;
typedef struct segment_command_64 t_segment_command_64;
typedef struct section t_section;
typedef struct section_64 t_section_64;
typedef struct symtab_command t_symtab_command;

typedef struct nlist_64 t_nlist;

//struct nlist {
//
//	union {
//		char *n_name;	/* symbol name (in memory) */
//		long n_strx;	/* file string table offset (on disk) */
//	} n_un;
//
//#define	N_UNDF	0x00		/* undefined */
//#define	N_ABS	0x02		/* absolute address */
//#define	N_TEXT	0x04		/* text segment */
//#define	N_DATA	0x06		/* data segment */
//#define	N_BSS	0x08		/* bss segment */
//#define	N_COMM	0x12		/* common reference */
//#define	N_FN	0x1e		/* file name */
//
//#define	N_EXT	0x01		/* external (global) bit, OR'ed in */
//#define	N_TYPE	0x1e		/* mask for all the type bits */
//	unsigned char n_type;	/* type defines */
//
//	char n_other;		/* spare */
//#define	n_hash	n_desc		/* used internally by ld(1); XXX */
//	short n_desc;		/* used by stab entries */
//	unsigned long n_value;	/* address/value of the symbol */
//};

#endif
