/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <gemerald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:22:07 by gemerald          #+#    #+#             */
/*   Updated: 2020/11/04 22:22:39 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int     error_file_corrupt(char *file_name)
{
	ft_putstr_fd("ft_nm: error: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": file corrupt.", 2);
	return (FALSE);
}

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