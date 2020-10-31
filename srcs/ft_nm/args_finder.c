//
// Created by Grass Emerald on 10/28/20.
//

#include "args.h"
#include "libft.h"
#include "constants.h"

int     contains_char_sym(char *str, char to_count)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == to_count)
			return TRUE;
	}
	return FALSE;
}

int     is_correct_flag(char f)
{
	if (contains_char_sym(ARGS_SYMBOLS, f))
		return TRUE;
	return FALSE;
}

void    set_flag(char f, t_args *args)
{
	if (f == 'o')
		args->flag_o++;
	if (f == 'n')
		args->flag_n++;
	if (f == 'u')
		args->flag_u++;
	if (f == 'U')
		args->flag_big_u++;
	if (f == 'j')
		args->flag_j++;
}

void    find_args(char *str, t_args *args)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (is_correct_flag(str[i]))
			set_flag(str[i], args);
		else
		{
			ft_lstadd(&args->bad_argums, ft_lstnew(str, ft_strlen(str) + 1));
			break;
		}
	}
}

int     is_argums(char *av)
{
	if (ft_strlen(av) < 2)
		return FALSE;
	if (av[0] == '-')
		return TRUE;
	return FALSE;
}

void    pars_args(char *av, t_args *args)
{
	if(is_argums(av))
	{
		find_args(&av[1], args);
	}
	else
	{
		ft_lstadd(&args->filenames, ft_lstnew(av, ft_strlen(av) + 1));
	}
}

t_args    *take_args(int ac, char **av)
{
	int i;
	t_args *args;

	if (!(args = ft_memalloc(sizeof(t_args))))
		return (NULL);
	i = 0;
	while (++i < ac)
	{
		pars_args(av[i], args);
	}
	return args;
}