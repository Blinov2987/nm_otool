/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:50:12 by gemerald          #+#    #+#             */
/*   Updated: 2020/10/30 22:00:21 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_FILE_INFO_H
#define NM_FILE_INFO_H

typedef enum e_filename
{
	OBJECT,
	OBJECT_64,
	FAT_OBJECT,
	ARCH
} t_file_type;

typedef struct s_file
{
	char *file_name;
	int fd;
	size_t size;
	t_file_type file_type;
} t_file;

#endif
