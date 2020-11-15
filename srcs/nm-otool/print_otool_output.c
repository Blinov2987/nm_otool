/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_otool_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:06:53 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/13 13:32:54 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint64_t	get_start_addr(t_file *file)
{
	uint64_t	i;
	uint64_t	min;

	i = 0;
	min = 0xFFFFFFFFFFFF;
	while (i < file->out_size)
	{
		if (file->output[i].value < min && file->output[i].type == 'T'
		&& ft_strcmp(file->output[i].name, "__mh_execute_header"))
			min = file->output[i].value;
		i++;
	}
	return (min);
}

void		print_text_64(t_file *file, t_section_64 *section_64)
{
	uint64_t	j;
	uint64_t	i;
	void		*start_code;
	uint64_t	value;

	start_code = (void *)(file->start + section_64->offset);
	value = get_start_addr(file);
	j = 0;
	while (j < section_64->size)
	{
		i = 0;
		ft_printf("%016lx\t", value);
		value += 16;
		while (i < 16 && (j + i) < section_64->size)
		{
			ft_printf("%02x ", ((unsigned char *)start_code)[j + i]);
			i++;
		}
		ft_printf("\n");
		j += 16;
	}
}

void		print_text(t_file *file, t_section *section)
{
	uint32_t	j;
	uint32_t	i;
	void		*start_code;
	uint32_t	value;

	start_code = (void *)(file->start + section->offset);
	value = get_start_addr(file);
	j = 0;
	while (j < section->size)
	{
		i = 0;
		ft_printf("%08lx\t", value);
		value += 16;
		while (i < 16 && (j + i) < section->size)
		{
			ft_printf("%02x ", ((unsigned char *)start_code)[j + i]);
			i++;
		}
		ft_printf("\n");
		j += 16;
	}
}

void		print_otool_32(t_file *file)
{
	t_section	*section;
	t_list		*sections;

	sections = file->section_list;
	while (sections)
	{
		section = sections->content;
		if (!ft_strcmp(section->sectname, "__text"))
		{
			ft_printf("%s:\n", file->name);
			ft_printf("Contents of (__TEXT,__text) section\n");
			print_text(file, section);
		}
		sections = sections->next;
	}
}

void		print_otool(t_file *file)
{
	t_section_64	*section_64;
	t_list			*sections;

	if (!file->is_64)
	{
		print_otool_32(file);
		return ;
	}
	sections = file->section_list;
	while (sections)
	{
		section_64 = sections->content;
		if (!ft_strcmp(section_64->sectname, "__text"))
		{
			ft_printf("%s:\n", file->name);
			ft_printf("Contents of (__TEXT,__text) section\n");
			print_text_64(file, section_64);
		}
		sections = sections->next;
	}
}
