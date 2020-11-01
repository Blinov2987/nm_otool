/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walker_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:04:42 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/01 18:56:05 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int     walk_magic_64(t_args *args, t_file *file)
{
	t_mach_header_64 *header_64;
	void    *start;
	size_t off_set;
	uint64_t symb_offset;
	uint64_t strtab_offset;
	t_load_command *load_command[15];
	t_segment_command_64 *segment_command_64;
	t_symtab_command *symtab_command;
	t_nlist *symb;

	//load_command = ft_memalloc(sizeof(t_load_command));
	ft_bzero(load_command, sizeof(t_load_command *) * 15);
	start = mmap(NULL, file->size, PROT_READ, MAP_PRIVATE, file->fd, 0);
	off_set = start + sizeof(t_mach_header_64);
	header_64 = mmap(NULL, sizeof(t_mach_header_64), PROT_READ, MAP_PRIVATE, file->fd, 0);
	int i = -1;
	uint64_t j = 0;
	while (++i < 15)
	{
		load_command[i] = (t_load_command *) (off_set);
		if (load_command[i]->cmd == 0x2)
		{
			symtab_command = (t_symtab_command *) (off_set);
			symb_offset = symtab_command->symoff;// + start;
			strtab_offset = symtab_command->stroff;// + start;
			uint32_t len = 0;
			while (j < 143)
			{
				symb = (start + symb_offset);
				char *name = start + strtab_offset + symb->n_un.n_strx;
//				len += ft_strlen(name) + 1;
//				int ind = 1;
				symb_offset += sizeof(t_nlist);
				j++;
			}
		}
		segment_command_64 = (t_segment_command_64 *) (off_set);
		off_set += load_command[i]->cmdsize;
	}
	//segment_command_64 = mmap(NULL, sizeof(t_segment_command_64), PROT_READ, MAP_PRIVATE, file->fd, off_set);
	return (TRUE);
}