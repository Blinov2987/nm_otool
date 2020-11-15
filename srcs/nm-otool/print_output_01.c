/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:53:59 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/13 13:33:26 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	print_simple(t_file *file, t_args *args)
{
	size_t		i;
	t_output	*output;

	i = -1;
	while (++i < file->out_size)
	{
		output = &file->output[i];
		if (args->flag_big_u && output->type != 'U')
		{
			print_file_name(file, args);
			ft_printf("%08lx %c %s\n", output->value,
					output->type, output->name);
		}
		else if (!args->flag_big_u && !args->flag_u)
		{
			print_file_name(file, args);
			if (output->value)
				ft_printf("%08lx ", output->value);
			else
				ft_printf("%08c ", ' ');
			ft_printf("%c %s\n", output->type, output->name);
		}
	}
}
