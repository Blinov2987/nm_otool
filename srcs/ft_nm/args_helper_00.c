/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helper_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:10:38 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/04 23:10:38 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int     contains_char_sym(char *str, char to_count)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == to_count)
			return TRUE;
	}
	return FALSE;
}

int     is_correct_flag(char f)
{
	if (contains_char_sym(ARGS_SYMBOLS, f))
		return TRUE;
	return FALSE;
}

void    set_flag(char f, t_args *args)
{
	if (f == 'o')
		args->flag_o++;
	if (f == 'n')
		args->flag_n++;
	if (f == 'u')
		args->flag_u++;
	if (f == 'U')
		args->flag_big_u++;
	if (f == 'j')
		args->flag_j++;
}

void    find_args(char *str, t_args *args)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (is_correct_flag(str[i]))
			set_flag(str[i], args);
		else
		{
			ft_lstadd(&args->bad_argums, ft_lstnew(str, ft_strlen(str) + 1));
			break;
		}
	}
}