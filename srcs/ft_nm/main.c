//
// Created by Grass Emerald on 10/28/20.
//
#include "nm.h"

int     error_exit(char *error_message, int error)
{
	ft_printf("We have trabl!\n%s\nerror code %d", error_message, error);
	return error;
}

int    print_usage(void)
{
	ft_printf("usage:\n");
	ft_printf("\t\t ft_nm -[o | n | u | U | j] <file_name>\n");
	return FALSE;
}

void    print_multiple_flags_errors(t_args *args)
{
	if (args->flag_o > 1)
		ft_putstr_fd(
				"ft_nm: for the -print-file-name option: may only occur zero or one times!\n",
				2
					);
	if (args->flag_big_u > 1)
		ft_putstr_fd(
				"ft_nm: for the -defined-only option: may only occur zero or one times!\n",
				2
					);
	if (args->flag_j > 1)
		ft_putstr_fd(
				"ft_nm: for the -just-symbol-name option: may only occur zero or one times!\n",
				2
					);
	if (args->flag_u > 1)
		ft_putstr_fd(
				"ft_nm: for the -undefined-only option: may only occur zero or one times!\n",
				2
					);
	if (args->flag_n > 1)
		ft_putstr_fd(
				"ft_nm: for the -numeric-sort option option: may only occur zero or one times!\n",
				2
					);
}

void    print_bad_argums_error(t_args *args)
{
	t_list *iter;

	iter = args->bad_argums;
	while (iter)
	{
		ft_putstr_fd("ft_nm: Unknown command line argument '-", 2);
		ft_putstr_fd(iter->content, 2);
		ft_putstr_fd("'\n", 2);
		iter = iter->next;
	}
}

int    validate_args(t_args **args, int ac)
{
	if (ac < 2)
		return (print_usage());
	if ((*args)->flag_o > 1 || (*args)->flag_big_u > 1 || (*args)->flag_j > 1 ||
			(*args)->flag_u > 1 || (*args)->flag_n > 1 || (*args)->bad_argums)
	{
		if ((*args)->flag_o > 1 || (*args)->flag_big_u > 1 || (*args)->flag_j > 1 ||
				(*args)->flag_u > 1 || (*args)->flag_n > 1)
		{
			print_multiple_flags_errors(*args);
		}
		if ((*args)->bad_argums)
		{
			print_bad_argums_error(*args);
		}
		free_args(args);
		return FALSE;
	}
	return TRUE;
}

int     main(int ac, char **av)
{
	t_args *args;

	args = take_args(ac, av);
	validate_args(&args, ac);
	init_analytics(args);
	free_args(&args);
	return 0;
}