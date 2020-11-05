/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:59:27 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 13:59:27 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int     main(int ac, char **av)
{
	t_args *args;

	args = take_args(ac, av);
	args->is_outool = TRUE;
	if (validate_args(&args, ac))
		init_analytics(args);
	free_args(&args);
	return 0;
}