/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:44:34 by oespion           #+#    #+#             */
/*   Updated: 2018/07/14 17:44:42 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		check_a(int ac, char **av)
{
	int	r;
	int	i;

	i = 0;
	r = 1;
	if (ac > 1)
	{
		if (av[r][0] == '-' && av[r][1] == 'v' && av[r][2] == '\0')
			r++;
		while (r < ac)
		{
			if (av[r][i] == '-')
				i++;
			while (av[r][i])
			{
				if (av[r][i] < '0' || av[r][i] > '9')
					return (0);
				i++;
			}
			i = 0;
			r++;
		}
	}
	return (1);
}

int		checker_str(char *str)
{
	int	r;


	r = 0;
	while (str[r])
	{
		if ((str[r] < '0' || str[r] > '9') && str[r] != '-')
			break ;
		if (str[r] == '-')
			r++;
		while (str[r] >= '0' && str[r] <= '9')
			r++;
		if (str[r] == ' ')
			r++;
	}
	if (str[r - 1] >= '0' && str[r - 1] <= '9' && str[r] == '\0')
		return (1);
	return (0);
}
