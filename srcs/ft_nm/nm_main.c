/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:42:07 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 11:02:06 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int     main(int ac, char **av)
{
	t_args *args;

	args = take_args(ac, av);
	if (validate_args(&args, ac))
		init_analytics(args);
	free_args(&args);
	return 0;
}