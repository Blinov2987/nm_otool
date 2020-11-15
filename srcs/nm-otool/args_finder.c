/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:10:03 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 18:42:01 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		is_argums(char *av)
{
	if (ft_strlen(av) < 2)
		return (FALSE);
	if (av[0] == '-')
		return (TRUE);
	return (FALSE);
}

void	pars_args(char *av, t_args *args)
{
	if (is_argums(av))
		find_args(&av[1], args);
	else
		ft_lstadd(&args->filenames, ft_lstnew(av, ft_strlen(av) + 1));
}

t_args	*take_args(int ac, char **av)
{
	int		i;
	t_args	*args;

	if (!(args = ft_memalloc(sizeof(t_args))))
		return (NULL);
	i = 0;
	while (++i < ac)
	{
		pars_args(av[i], args);
	}
	if (args->filenames && args->filenames->next)
		args->is_multi_file = TRUE;
	return (args);
}

int		validate_args(t_args **args, int ac)
{
	if (ac < 2)
		return (print_usage(*args));
	if ((*args)->flag_o > 1 || (*args)->flag_big_u > 1 || (*args)->flag_j > 1 ||
			(*args)->flag_u > 1 || (*args)->flag_n > 1 || (*args)->bad_argums)
	{
		if ((*args)->flag_o > 1 || (*args)->flag_big_u > 1 ||
				(*args)->flag_j > 1 ||
				(*args)->flag_u > 1 || (*args)->flag_n > 1)
			error_print_multiple_flags(*args);
		if ((*args)->bad_argums)
			error_print_bad_argums(*args);
		return (FALSE);
	}
	if (!(*args)->filenames)
		return (print_usage(*args));
	return (TRUE);
}
