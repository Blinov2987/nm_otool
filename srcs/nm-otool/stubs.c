/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stubs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:13:45 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 13:13:45 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int walk_magic(t_file *file)
{
	ft_printf("Unsupported file type\n");
	return (FALSE);
}

int walk_fat_magic(t_file *file)
{
	ft_printf("Unsupported file type\n");
	return (FALSE);
}

int walk_fat_magic_64(t_file *file)
{
	ft_printf("Unsupported file type\n");
	return (FALSE);
}