/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walker_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:57:53 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/13 13:36:44 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		see_in_segment_moment(void *start, size_t off_set, t_file *file)
{
	t_segment_command	*segment;
	t_section			*section;
	uint64_t			i;

	i = 0;
	segment = (t_segment_command *)(start + off_set);
	if (segment->nsects > 0)
	{
		off_set += sizeof(t_segment_command);
	}
	while (i < segment->nsects)
	{
		section = (t_section *)(start + off_set);
		file->nsections++;
		ft_lstadd(&file->section_list,
				ft_lstnew((section), sizeof(t_section)));
		off_set += sizeof(t_section);
		if (off_set >= file->size)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	*find_section(t_file *file, uint8_t index)
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
			return ((t_section *)sections->content)->sectname;
		sections = sections->next;
		i++;
	}
	return (NULL);
}
