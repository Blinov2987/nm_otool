/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:13:46 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/04 23:13:46 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "args.h"
#include "file_info.h"

void    free_list(void *mem, size_t size)
{
	if (!size)
		size++;
	if (mem)
	{
		free(mem);
		mem = NULL;
	}
}

void    free_args(t_args **args)
{
	if (*args)
	{
		ft_lstdel(&(*args)->bad_argums, &free_list);
		ft_lstdel(&(*args)->filenames, &free_list);
		(*args)->bad_argums = NULL;
		(*args)->filenames = NULL;
		free(*args);
		(*args) = NULL;
	}
}

void    free_file(t_file **file)
{
	if (*file)
	{
		ft_lstdel(&(*file)->segment_list, &free_list);
		(*file)->segment_list = NULL;
		ft_lstdel(&(*file)->section_list, &free_list);
		(*file)->section_list = NULL;
		if ((*file)->output)
			free((*file)->output);
		(*file)->output = NULL;
		free(*file);
		(*file) = NULL;
	}
}