/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:35:45 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/05 18:33:38 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_ERRORS_H
# define NM_ERRORS_H

# include "args.h"

int		print_usage(t_args *args);
int		error_file_corrupt(char *file_name);
int		error_open_file(char *file_name);
int		error_bad_file_descriptor(char *file_name);
int		error_read_file(char *file_name);
int		error_recognize_file(char *file_name);
void	error_print_multiple_flags(t_args *args);
void	error_print_bad_argums(t_args *args);

#endif
