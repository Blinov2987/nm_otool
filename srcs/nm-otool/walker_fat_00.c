/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walker_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:04:42 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/13 14:02:39 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint32_t		swap_bytes(void *src, size_t n)
{
	uint32_t		swap;
	size_t			i;
	unsigned char	*dst;

	swap = 0;
	dst = NULL;
	i = 0;
	dst = (unsigned char*)&swap;
	while (i < n / 1)
	{
		dst[i] = ((unsigned char *)src)[n - 1 - i];
		dst[n - 1 - i] = ((unsigned char *)src)[i];
		i++;
	}
	return (swap);
}

void			swap_fat_arch(t_fat_arch *arch)
{
	arch->size = swap_bytes(&arch->size, sizeof(uint32_t));
	arch->offset = swap_bytes(&arch->offset, sizeof(uint32_t));
	arch->align = swap_bytes(&arch->align, sizeof(uint32_t));
}

int				take_macho_from_fat(t_file *file,
							t_fat_arch fat_archs[], uint32_t n_arch)
{
	uint32_t	magic_header;
	int			is_64;
	int			find_macho;
	size_t		i;

	i = 0;
	is_64 = FALSE;
	find_macho = 0;
	while (i < n_arch && i < 5)
	{
		magic_header = *(uint32_t *)(file->start + fat_archs[i].offset);
		if (magic_header == MH_MAGIC_64 || magic_header == MH_CIGAM_64)
		{
			is_64 = TRUE;
			break ;
		}
		if (magic_header == MH_MAGIC || magic_header == MH_CIGAM)
			find_macho = i;
		i++;
	}
	if (is_64)
		find_macho = i;
	file->start += fat_archs[find_macho].offset;
	file->size = fat_archs[find_macho].size;
	return (is_64);
}

int				extrud_from_fat(t_file *file, int is_swap, size_t off_set)
{
	t_fat_header	header;
	t_fat_arch		fat_archs[5];
	size_t			i;

	i = 0;
	ft_bzero(&fat_archs, sizeof(t_fat_arch) * 5);
	header = *(t_fat_header *)file->start;
	if (is_swap)
		swap_fat_header(&header);
	while (i < header.nfat_arch && i < 5)
	{
		fat_archs[i] = *(t_fat_arch *)(file->start + off_set);
		swap_fat_arch(&fat_archs[i]);
		off_set += sizeof(t_fat_arch);
		i++;
	}
	if (take_macho_from_fat(file, fat_archs, header.nfat_arch))
		return (walk_magic_64(file));
	return (walk_magic(file));
}

int				walk_magic_fat(t_file *file)
{
	t_fat_header	*header_fat;
	size_t			off_set;
	int				is_swap;

	off_set = sizeof(t_fat_header);
	is_swap = FALSE;
	header_fat = (t_fat_header *)file->start;
	if (header_fat->magic == FAT_CIGAM || header_fat->magic == FAT_CIGAM_64)
		is_swap = TRUE;
	if (header_fat->magic == FAT_MAGIC || header_fat->magic == FAT_CIGAM)
		return (extrud_from_fat(file, is_swap, off_set));
	else
		return (extrud_from_fat_64(file, is_swap, off_set));
}
