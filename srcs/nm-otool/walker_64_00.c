/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walker_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:04:42 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/13 13:37:45 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

unsigned char	find_in_symbol_section_64(t_file *file, t_nlist_64 *command)
{
	char *name;

	name = find_section_64(file, command->n_sect);
	if (name)
	{
		if (!ft_strcmp(name, SECT_DATA))
			return ('D');
		else if (!ft_strcmp(name, SECT_TEXT))
			return ('T');
		else if (!ft_strcmp(name, SECT_BSS))
			return ('B');
		else
			return ('S');
	}
	return ('!');
}

void			set_entry_type_64(t_nlist_64 *command, t_file *file,
		t_output *output)
{
	if ((N_TYPE & command->n_type) == N_SECT)
		output->type = find_in_symbol_section_64(file, command);
	else if (N_STAB & command->n_type)
		output->type = '-';
	else if ((N_TYPE & command->n_type) == N_UNDF)
	{
		if (command->n_type & N_EXT)
			output->type = 'U';
		else
			output->type = '?';
	}
	else if ((N_TYPE & command->n_type) == N_INDR)
		output->type = 'I';
	else if ((N_TYPE & command->n_type) == N_ABS)
		output->type = 'A';
}

int				parse_symtab_64(void *start, size_t off_set, t_file *file)
{
	uint64_t			symb_offset;
	t_nlist_64			*symb;
	t_symtab_command	*symtab_command;
	uint64_t			j;

	j = 0;
	symtab_command = (t_symtab_command *)(start + off_set);
	symb_offset = symtab_command->symoff;
	file->output = ft_memalloc(sizeof(t_output) * symtab_command->nsyms);
	file->out_size = symtab_command->nsyms;
	while (j < symtab_command->nsyms)
	{
		symb = (start + symb_offset);
		file->output[j].name = start + symtab_command->stroff +
			symb->n_un.n_strx;
		file->output[j].value = symb->n_value;
		symb_offset += sizeof(t_nlist_64);
		if (symb_offset >= file->size)
			return (FALSE);
		set_entry_type_64(symb, file, &file->output[j]);
		j++;
	}
	return (TRUE);
}

int				save_commands_64(size_t off_set,
				t_file *file, t_load_command *command)
{
	if (command->cmd == LC_SEGMENT_64)
	{
		if (!(see_in_segment_moment_64(file->start, off_set, file)))
			return (FALSE);
		ft_lstadd(&file->segment_list,
				ft_lstnew(((t_segment_command_64 *)(file->start + off_set)),
						sizeof(t_segment_command_64)));
	}
	if (command->cmd == LC_SYMTAB && !parse_symtab_64(file->start, off_set,
			file))
		return (FALSE);
	return (TRUE);
}

int				walk_magic_64(t_file *file)
{
	t_mach_header_64	*header_64;
	size_t				off_set;
	t_load_command		*load_command;
	uint64_t			i;

	off_set = sizeof(t_mach_header_64);
	i = 0;
	file->is_64 = TRUE;
	header_64 = (t_mach_header_64 *)file->start;
	while (i < header_64->ncmds)
	{
		load_command = (t_load_command *)(file->start + off_set);
		save_commands_64(off_set, file, load_command);
		off_set += load_command->cmdsize;
		if (off_set >= file->size)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
