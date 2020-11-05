/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:49:24 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 11:53:17 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void    number_sort(t_file *file)
{
	size_t i;
	size_t j;
	t_output swap;

	i = 0;
	while (i < file->out_size - 1)
	{
		j = i;
		while (++j < file->out_size)
		{
			if (file->output[i].value > file->output[j].value)
			{
				swap = file->output[j];
				file->output[j] = file->output[i];
				file->output[i] = swap;
			}
		}
		i++;
	}
}

void    literal_sort(t_file *file)
{
	size_t i;
	size_t j;
	t_output swap;

	i = 0;
	while (i < file->out_size - 1)
	{
		j = i;
		while (++j < file->out_size)
		{
			if (ft_strcmp(file->output[i].name, file->output[j].name) > 0)
			{
				swap = file->output[j];
				file->output[j] = file->output[i];
				file->output[i] = swap;
			}
		}
		i++;
	}
}

void    make_sort(t_file *file, t_args *args)
{
	if (args->flag_n)
		number_sort(file);
	else
		literal_sort(file);
}