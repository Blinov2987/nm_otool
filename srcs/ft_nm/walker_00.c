/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walker_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:04:42 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/04 21:24:54 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

char    *find_mysection(t_file *file, uint8_t index)
{
	uint8_t i;
	uint8_t len;
	t_list *sections;

	i = 0;
	len = file->nsections - index;
	sections = file->section_list;
	while(sections)
	{
		if (i == len)
			return ((t_section_64 *)sections->content)->sectname;
		sections = sections->next;
		i++;
	}
	return (NULL);
}

unsigned char find_in_symbol_section(t_file *file, t_nlist *command)
{
	char *name;

	if (name = find_mysection(file, command->n_sect))
	{
		if (!ft_strcmp(name, SECT_TEXT))
			return ('T');
		else if (!ft_strcmp(name, SECT_DATA))
			return ('D');
		else if (!ft_strcmp(name, SECT_BSS))
			return ('B');
		else
			return ('S');
	}
	return ('?');
}

void    set_entry_type(t_nlist *command, t_file *file, t_output *output)
{
	if (N_STAB & command->n_type)
		output->type =  '-';
	else if ((N_TYPE & command->n_type) == N_UNDF)
	{
		if (command->n_type & N_EXT)
			output->type = 'U';
		else
			output->type = '?';
	}
	else if ((N_TYPE & command->n_type) == N_SECT)
		output->type =  find_in_symbol_section(file, command);
	else if ((N_TYPE & command->n_type) == N_ABS)
		output->type = 'A';
	else if ((N_TYPE & command->n_type) == N_INDR)
		output->type = 'I';
}

void  *parse_symtab(void *start, size_t off_set, t_file *file)
{
	uint64_t symb_offset;
	t_nlist *symb;
	t_symtab_command *symtab_command;
	int j;

	j = 0;
	symtab_command = (t_symtab_command *)(start + off_set);
	symb_offset = symtab_command->symoff;
	file->output = ft_memalloc(sizeof(t_output) * symtab_command->nsyms);
	file->out_size = symtab_command->nsyms;
	while (j < symtab_command->nsyms)
	{
		symb = (start + symb_offset);
		file->output[j].name = start + symtab_command->stroff + symb->n_un.n_strx;
		file->output[j].value = symb->n_value;
		symb_offset += sizeof(t_nlist);
		if (symb_offset >= file->size)
			return (NULL);
		set_entry_type(symb, file, &file->output[j]);
		j++;
	}
}

void *see_in_segment_moment(void *start, size_t off_set, t_file *file)
{
	t_segment_command_64 *segment;
	t_section_64 *section_64;
	int i;

	i = -1;

	segment = (t_segment_command_64 *) (start + off_set);
	if (segment->nsects > 0)
	{
		off_set += sizeof(t_segment_command_64);
	}
	while (++i < segment->nsects)
	{
		section_64 = (t_section_64 *) (start + off_set);
		file->nsections++;
		ft_lstadd(&file->section_list, ft_lstnew((section_64), sizeof(t_section_64 *)));
		int y = 0;
//		if (!ft_strcmp(section_64->sectname, "__text"))
//		{
//			void *start_code = (void *) (start + section_64->offset);
//			int j = -1;
//			while (++j < section_64->size)
//			{
//				if (j != 0 && !((j) % 16))
//					ft_printf("\n");
//				ft_printf("%02x ", ((unsigned char *) start_code)[j]);
//			}
//		}
		off_set += sizeof(t_section_64);
		if (off_set >= file->size)
			return (NULL);
		int x = 0;
	}
}

int walk_magic_64(t_file *file)
{
	t_mach_header_64 *header_64;
	size_t off_set;
	t_load_command *load_command;
	int i = -1;

	file->start = mmap(NULL, file->size, PROT_READ, MAP_PRIVATE, file->fd, 0);
	off_set = sizeof(t_mach_header_64);
	header_64 = mmap(NULL, sizeof(t_mach_header_64), PROT_READ, MAP_PRIVATE, file->fd, 0);
	int command_count = header_64->ncmds;
	while (++i < command_count)
	{
		load_command = (t_load_command *)(file->start + off_set);
		if (load_command->cmd == LC_SEGMENT_64)
		{
			see_in_segment_moment(file->start, off_set, file);
			ft_lstadd(&file->segment_list,
					ft_lstnew(((t_segment_command_64 *) (file->start + off_set)), sizeof(t_segment_command_64)));
		}
		if (load_command->cmd == LC_SYMTAB)
		{
			parse_symtab(file->start, off_set, file);
		}
		if (off_set >= file->size)
			return (FALSE);
		off_set += load_command->cmdsize;
	}
	return (TRUE);
}