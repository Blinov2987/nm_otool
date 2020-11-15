/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:50:12 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/13 13:28:55 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_FILE_INFO_H
# define NM_FILE_INFO_H

typedef struct s_output		t_output;

typedef enum				e_filename
{
	MAGIC_TYPE = 0,
	MAGIC_64_TYPE = 1,
	FAT_MAGIC_TYPE = 2,
	FAT_MAGIT_64_TYPE = 3
}							t_file_type;

typedef struct				s_file
{
	char					*name;
	int						fd;
	size_t					size;
	int						is_64;
	uint32_t				header;
	void					*start;
	t_list					*segment_list;
	t_list					*section_list;
	size_t					nsections;
	t_output				*output;
	size_t					out_size;
}							t_file;

struct						s_output
{
	uint64_t				value;
	unsigned char			type;
	char					*name;
};

void						free_file(t_file **file);

#endif
