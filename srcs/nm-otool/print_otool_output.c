/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_otool_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:06:53 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 12:53:01 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint64_t   get_start_addr(t_file *file)
{
	int i;
	uint64_t min;

	i = -1;
	min = 0xFFFFFFFFFFFF;
	while (++i < file->out_size)
	{
		if (file->output[i].value < min && file->output[i].type == 'T')
			min = file->output[i].value;
	}
	return (min);
}

void    print_text(t_file *file, t_section_64 *section_64)
{
	int j;
	void *start_code;
	uint64_t value;

	start_code = (void *) (file->start + section_64->offset);
	value = get_start_addr(file);
	j = -1;
	while (++j < section_64->size)
	{
		if (j == 0 || j % 16 == 1)
		{
			ft_printf("%016lx        ", value);
			value += 16;
		}
		if (j != 0 && !((j) % 16))
			ft_printf("\n");
		ft_printf("%02x ", ((unsigned char *) start_code)[j]);
	}
}

void    print_otool(t_file *file)
{
	t_section_64 *section_64;
	t_list *sections;
	int j;

	sections = file->section_list;
	while (sections)
	{
		section_64 = sections->content;
		if (!ft_strcmp(section_64->sectname, "__text"))
		{
			ft_printf("%s:\n", file->name);
			ft_printf("Contents of (__TEXT,__text) section");
			print_text(file, section_64);
		}
		sections = sections->next;
	}
}