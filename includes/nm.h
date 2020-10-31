/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:17:46 by gemerald          #+#    #+#             */
/*   Updated: 2020/10/31 15:17:46 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NM_NM_H
#define NM_NM_H

#include "libft.h"
#include "printf.h"
#include "args.h"
#include "headers.h"
#include "file_info.h"
#include "constants.h"
#include <sys/mman.h>

void    init_analytics(t_args *args);
int     walk_magic_64(t_args *args, t_file *file);

#endif
