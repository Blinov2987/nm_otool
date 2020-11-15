/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walker_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:57:53 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/13 14:02:58 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	swap_fat_header(t_fat_header *header)
{
	header->nfat_arch = swap_bytes(&header->nfat_arch, sizeof(uint32_t));
}
