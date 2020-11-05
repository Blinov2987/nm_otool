/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taste_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:40:54 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 13:12:32 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <sys/stat.h>

int     open_file(char *file_name, t_file *file)
{
	int fd;
	struct stat buf;

	if ((fd = open(file_name, O_RDONLY)) < 2)
		return (error_open_file(file_name));
	if ((fstat(fd, &buf)) < 0)
		return (error_bad_file_descriptor(file_name));
	if (((buf.st_mode) & S_IFMT) == S_IFDIR)
		return (error_read_file(file_name));
	if (buf.st_size < 8)
		return (error_recognize_file(file_name));
	file->name = file_name;
	file->fd = fd;
	file->size = buf.st_size;
	return (TRUE);
}

int     recognize_header(t_file *file)
{
	uint32_t *header;

	file->start = mmap(NULL, file->size, PROT_READ, MAP_PRIVATE, file->fd, 0);
	header = (uint32_t *)file->start;
	if (*header == MH_MAGIC_64 || *header == MH_MAGIC
		|| *header == FAT_MAGIC || *header == FAT_MAGIC_64)
	{
		file->header = *header;
		return (TRUE);
	}
	return error_recognize_file(file->name);
}

void    init_walker(int (*walk_through[])(t_file *))
{
	walk_through[0] = &walk_magic;
	walk_through[1] = &walk_magic_64;
	walk_through[2] = &walk_fat_magic;
	walk_through[3] = &walk_fat_magic_64;
}

int     select_file_type(t_file *file)
{
	if (file->header == MH_MAGIC)
		return (MAGIC_TYPE);
	if (file->header == MH_MAGIC_64)
		return (MAGIC_64_TYPE);
	if (file->header == FAT_MAGIC)
		return (FAT_MAGIC_TYPE);
	if (file->header == FAT_MAGIC_64)
		return (FAT_MAGIT_64_TYPE);
	return (5);
}

void    init_analytics(t_args *args)
{
	t_list *files;
	t_file *file;
	int     (*walk_through[4])(t_file *);

	files = args->filenames;
	init_walker(walk_through);
	while (files)
	{
		file = ft_memalloc(sizeof(t_file));
		if (open_file(files->content, file) && recognize_header(file))
		{
			if (walk_through[select_file_type(file)](file))
				print_output(file, args);
			else
				error_file_corrupt(file->name);
		}
		free_file(&file);
		files = files->next;
	}
}