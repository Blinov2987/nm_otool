/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:37:58 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 11:02:06 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int    print_usage(void)
{
	ft_printf("usage:\n");
	ft_printf("\t\t nm-otool -[o | n | u | U | j] <name>\n");
	return FALSE;
}

void    error_print_multiple_flags(t_args *args)
{
	ft_putstr_fd("nm-otool: for the ",2);
	if (args->flag_o > 1)
		ft_putstr_fd("-print-file-name",2);
	if (args->flag_big_u > 1)
		ft_putstr_fd("-defined-only",2);
	if (args->flag_j > 1)
		ft_putstr_fd("-just-symbol-name",2);
	if (args->flag_u > 1)
		ft_putstr_fd("-undefined-only",2);
	if (args->flag_n > 1)
		ft_putstr_fd("-numeric-sort",2);
	ft_putstr_fd(" option: may only occur zero or one times!\n",2);
}

void    error_print_bad_argums(t_args *args)
{
	t_list *iter;

	iter = args->bad_argums;
	while (iter)
	{
		ft_putstr_fd("nm-otool: Unknown command line argument '-", 2);
		ft_putstr_fd(iter->content, 2);
		ft_putstr_fd("'\n", 2);
		iter = iter->next;
	}
}