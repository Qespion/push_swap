/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:23:55 by oespion           #+#    #+#             */
/*   Updated: 2018/08/11 15:37:57 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

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

int		check_doublon(t_list *a)
{
	t_list	*start;
	t_list	*tmp;
	int		nb;

	tmp = a;
	start = a;
	while (start->next != a)
	{
		nb = start->nb;
		tmp = start->next;
		while (tmp != a)
		{
			if (tmp->nb == nb)
				return (0);
			tmp = tmp->next;
		}
		start = start->next;
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
	{
		int_max(str);
		ft_strdel(&str);
		return (1);
	}
	return (0);
}

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
