/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:44:34 by oespion           #+#    #+#             */
/*   Updated: 2018/08/11 12:54:35 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

char	*mov_str(char *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == ' ')
		str++;
	return (str);
}

void	check_int_max(int ac, char **av)
{
	int		r;
	char	**tmp;
	char	*str;

	tmp = av;
	r = 1;
	if (ac > 1)
	{
		while (r < ac)
		{
			str = av[r++];
			while (*str)
			{
				if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
				{
					ft_printf("Error\n");
					exit(-1);
				}
				str = mov_str(str);
				if ((*str < '0' || *str > '9') && *str != ' ' && *str != '\0')
					return ;
			}
		}
	}
}

int		check_a(int ac, char **av)
{
	int	r;
	int	i;

	i = 0;
	r = 1;
	check_int_max(ac, av);
	if (ac > 1)
	{
		if (av[r][0] == '-' && av[r][1] == 'R' && av[r][2] == '\0')
			r++;
		while (r < ac)
		{
			if (av[r][i] == '-')
				i++;
			while (av[r][i])
			{
				if ((av[r][i] < '0' || av[r][i] > '9') && av[r][i] != ' ')
					return (0);
				i++;
			}
			i = 0;
			r++;
		}
	}
	return (1);
}

void	int_max(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (ft_atoi(tmp) > 2147483647 || ft_atoi(tmp) < -2147483648)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		tmp++;
	}
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
	{
		int_max(str);
		return (1);
	}
	return (0);
}
