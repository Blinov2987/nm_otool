/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walker_fat_64_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 12:31:37 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/13 14:08:37 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint64_t		swap_bytes_64(void *src, size_t n)
{
	uint64_t		swap_big;
	size_t			i;
	unsigned char	*dst;

	swap_big = 0;
	dst = NULL;
	i = 0;
	dst = (unsigned char*)&swap_big;
	while (i < n / 1)
	{
		dst[i] = ((unsigned char *)src)[n - 1 - i];
		dst[n - 1 - i] = ((unsigned char *)src)[i];
		i++;
	}
	return (swap_big);
}

void			swap_fat_arch_64(t_fat_arch_64 *arch)
{
	arch->size = swap_bytes_64(&arch->size, sizeof(uint64_t));
	arch->offset = swap_bytes_64(&arch->offset, sizeof(uint64_t));
	arch->align = swap_bytes_64(&arch->align, sizeof(uint64_t));
}

int				take_macho_from_fat_64(t_file *file,
							t_fat_arch_64 fat_archs[], uint32_t n_arch)
{
	uint32_t	*magic_header;
	int			is_64;
	int			find_macho;
	size_t		i;

	i = 0;
	is_64 = FALSE;
	find_macho = 0;
	while (i < n_arch && i < 5)
	{
		magic_header = (uint32_t *)(file->start + fat_archs[i].offset);
		if (*magic_header == MH_MAGIC_64 || *magic_header == MH_CIGAM_64)
		{
			is_64 = TRUE;
			break ;
		}
		if (*magic_header == MH_MAGIC || *magic_header == MH_CIGAM)
			find_macho = i;
		i++;
	}
	if (is_64)
		find_macho = i;
	file->start += fat_archs[find_macho].offset;
	file->size = fat_archs[find_macho].size;
	return (is_64);
}

int				extrud_from_fat_64(t_file *file, int is_swap, size_t off_set)
{
	t_fat_header	header;
	t_fat_arch_64	fat_archs[5];
	size_t			i;

	i = 0;
	ft_bzero(&fat_archs, sizeof(t_fat_arch_64) * 5);
	header = *(t_fat_header *)file->start;
	if (is_swap)
		swap_fat_header(&header);
	while (i < header.nfat_arch && i < 5)
	{
		fat_archs[i] = *(t_fat_arch_64 *)(file->start + off_set);
		swap_fat_arch_64(&fat_archs[i]);
		off_set += sizeof(t_fat_arch);
		i++;
	}
	if (take_macho_from_fat_64(file, fat_archs, header.nfat_arch))
		return (walk_magic_64(file));
	return (walk_magic(file));
}
