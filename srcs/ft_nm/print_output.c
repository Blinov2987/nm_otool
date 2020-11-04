/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:23:13 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/04 22:02:05 by gemerald         ###   ########.fr       */
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

void    multi_file(t_file *file, t_args *args)
{
	if (args->is_multi_file && !args->flag_o)
		ft_printf("%s:\n", file->name);
}

void    make_sort(t_file *file, t_args *args)
{
	if (args->flag_n)
		number_sort(file);
	else
		literal_sort(file);
}

void    print_file_name(t_file *file, t_args *args)
{
	if (args->flag_o)
		ft_printf("%s: ", file->name);
}

void    print_j(t_file *file, t_args *args)
{
	size_t i;
	t_output *output;

	i = -1;
	while (++i < file->out_size)
	{
		output = &file->output[i];
		if (args->flag_u && !args->flag_big_u && output->type == 'U')
		{
			print_file_name(file, args);
			ft_printf("%s\n", output->name);
		}
		else if (args->flag_big_u && !args->flag_u && output->type != 'U')
		{
			print_file_name(file, args);
			ft_printf("%s\n", output->name);
		}
		else if (!args->flag_big_u && !args->flag_u)
		{
			print_file_name(file, args);
			ft_printf("%s\n", output->name);
		}
	}
}

void    print_simple(t_file *file, t_args *args)
{
	size_t i;
	t_output *output;

	i = -1;
	while (++i < file->out_size)
	{
		output = &file->output[i];
		if (args->flag_big_u && output->type != 'U')
		{
			print_file_name(file, args);
			ft_printf("%016lx %c %s\n", output->value, output->type, output->name);
		}
		else if (!args->flag_big_u && !args->flag_u)
		{
			print_file_name(file, args);
			if (output->value)
				ft_printf("%016lx ", output->value);
			else
				ft_printf("%016c ", ' ');
			ft_printf("%c %s\n", output->type, output->name);
		}
	}
}

void    print_output(t_file *file, t_args *args)
{
	multi_file(file, args);
	make_sort(file, args);
	if (args->flag_j || args->flag_u)
		print_j(file, args);
	else
		print_simple(file, args);

}
