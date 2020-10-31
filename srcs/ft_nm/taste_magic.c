/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taste_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:40:54 by gemerald          #+#    #+#             */
/*   Updated: 2020/10/31 10:22:50 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <sys/stat.h>

int     error_open_file(char *file_name)
{
	ft_putstr_fd("ft_nm: error: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": No such file or directory.", 2);
	return (FALSE);
}

int     error_bad_file_descriptor(char *file_name)
{
	ft_putstr_fd("ft_nm: error: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": Bad descriptor.", 2);
	return (FALSE);
}

int     error_read_file(char *file_name)
{
	ft_putstr_fd("ft_nm: error: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": Is a directory.", 2);
	return (FALSE);
}

int     error_recognize_file(char *file_name)
{
	ft_putstr_fd("ft_nm: error: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": The file was not recognized as a valid object file.", 2);
	return (FALSE);
}

int     open_file(char *file_name, t_file *file)
{
	int fd;
	struct stat buf;
	char *taste_read;

	if ((fd = open(file_name, O_RDONLY)) < 2)
		return (error_open_file(file_name));
	if ((fstat(fd, &buf)) < 0)
		return (error_bad_file_descriptor(file_name));
	if (read(fd, &taste_read, 0) < 0)
		return (error_read_file(file_name));
	if (buf.st_size < 8)
		return (error_recognize_file(file_name));
	file->file_name = file_name;
	file->fd = fd;
	file->size = buf.st_size;
	return (TRUE);
}

void    free_file(t_file **file)
{
	if (*file)
	{
		free(*file);
		(*file) = NULL;
	}
}

void    reverse_byte(unsigned char header[], size_t size)
{
	size_t i;
	size_t len;
	unsigned char swap;

	i = -1;
	len = size - 1;
	while (++i < size / 2)
	{
		swap = header[i];
		header[i] = header[len];
		header[len] = swap;
	}
}

int     recognize_header(t_file *file)
{
	uint32_t header;

	read(file->fd, &header, sizeof(uint32_t));
	if (header == MH_MAGIC_64)
		return (TRUE);
	return FALSE;
}


void    init_analytics(t_args *args)
{
	t_list *files;
	t_file *file;

	files = args->filenames;
	while (files)
	{
		file = ft_memalloc(sizeof(t_file));
		if (open_file(files->content, file) && recognize_header(file))
		{
			ft_printf("mach %d\n", sizeof(t_mach_header));
			ft_printf("mach_64 %d\n", sizeof(t_mach_header_64));
			ft_printf("fat %d\n", sizeof(t_fat_header));
		}
		free_file(&file);
		files = files->next;
	}
}