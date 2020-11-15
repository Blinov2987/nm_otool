/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walker_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:57:53 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 19:05:08 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		see_in_segment_moment_64(void *start, size_t off_set, t_file *file)
{
	t_segment_command_64	*segment;
	t_section_64			*section_64;
	uint64_t				i;

	i = 0;
	segment = (t_segment_command_64 *)(start + off_set);
	if (segment->nsects > 0)
	{
		off_set += sizeof(t_segment_command_64);
	}
	while (i < segment->nsects)
	{
		section_64 = (t_section_64 *)(start + off_set);
		file->nsections++;
		ft_lstadd(&file->section_list,
				ft_lstnew((section_64), sizeof(t_section_64)));
		off_set += sizeof(t_section_64);
		if (off_set >= file->size)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	*find_section_64(t_file *file, uint8_t index)
{
	uint8_t	i;
	uint8_t	len;
	t_list	*sections;

	i = 0;
	len = file->nsections - index;
	sections = file->section_list;
	while (sections)
	{
		if (i == len)
			return ((t_section_64 *)sections->content)->sectname;
		sections = sections->next;
		i++;
	}
	return (NULL);
}
