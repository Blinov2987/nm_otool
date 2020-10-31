/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walker_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:04:42 by gemerald          #+#    #+#             */
/*   Updated: 2020/10/31 15:25:19 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int     walk_magic_64(t_args *args, t_file *file)
{
	t_mach_header_64 *header_64;
	size_t off_set;

	off_set = sizeof(t_mach_header_64);
	header_64 = mmap(NULL, sizeof(t_mach_header_64), PROT_READ, MAP_PRIVATE, file->fd, 0);

	return (TRUE);
}