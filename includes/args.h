//
// Created by Grass Emerald on 10/28/20.
//

#ifndef ARGS_H
# define ARGS_H

# include "libft.h"


typedef struct s_args
{
	char flag_o;
	char flag_n;
	char flag_u;
	char flag_big_u;
	char flag_j;
	t_list        *bad_argums;
	t_list        *filenames;
	int is_multi_file;
} t_args;

t_args    *take_args(int ac, char **av);
int    validate_args(t_args **args, int ac);
void    free_args(t_args **args);
void    find_args(char *str, t_args *args);

#endif
