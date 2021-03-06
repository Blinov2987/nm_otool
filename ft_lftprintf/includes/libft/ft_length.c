/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:07:27 by selly             #+#    #+#             */
/*   Updated: 2019/09/29 12:46:56 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_length(long long num, int flag)
{
	long long	i;

	i = 0;
	if (num < 0 && flag == 2)
	{
		i++;
		num = -num;
	}
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i);
}
