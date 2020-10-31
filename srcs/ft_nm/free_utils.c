//
// Created by Grass Emerald on 10/29/20.
//

#include "libft.h"
#include "args.h"
#include "nm.h"

void    free_list(void *mem, size_t size)
{
	if (mem)
	{
		free(mem);
		mem = NULL;
	}
}

void    free_args(t_args **args)
{
	if (*args)
	{
		ft_lstdel(&(*args)->bad_argums, &free_list);
		ft_lstdel(&(*args)->filenames, &free_list);
		free(*args);
		(*args) = NULL;
	}
}