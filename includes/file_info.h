/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:50:12 by gemerald          #+#    #+#             */
/*   Updated: 2020/10/31 13:08:11 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_FILE_INFO_H
#define NM_FILE_INFO_H

typedef enum e_filename
{
	MAGIC_TYPE = 0,
	MAGIC_64_TYPE = 1,
	FAT_MAGIC_TYPE = 2,
	FAT_MAGIT_64_TYPE = 3
} t_file_type;

typedef struct s_file
{
	char *file_name;
	int fd;
	size_t size;
	uint32_t header;
} t_file;

#endif
