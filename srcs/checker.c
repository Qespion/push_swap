/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:49:40 by oespion           #+#    #+#             */
/*   Updated: 2018/06/09 15:28:12 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	*create_a_from_str(char *str)
{
	t_list	*a;
	t_list	*start;

	a = ft_lstnew(ft_atoi(str));
	start = a;
	while (*str)
	{
		while (*str != ' ' && *str)
			str++;
		if (*str == ' ' && str[1] != '\0')
		{
			a = ft_lstaddone(ft_atoi(str), start, a);
			str++;
		}
	}
	return (start);
}

t_list	*create_a(int ac, char **av)
{
	t_list	*a;
	t_list	*start;
	int		r;

	r = 2;
	if (ac > 1)
	{
		a = ft_lstnew(ft_atoi(av[1]));
		start = a;
	}
	while (r < ac)
	{
		a = ft_lstaddone(ft_atoi(av[r]), start, a);
		r++;
	}
	return (start);
}

int		main(int ac, char **av)
{
	t_list	*a;
	char	*str;
	int		fd;

	if (ac < 2)
		return (1);
	fd = open(av[1], 0);
	if (get_next_line(fd, &str) == 1)
	{
		a = create_a_from_str(str);
		ft_strdel(&str);
		create_list(a);
	}
	else
	{
		a = create_a(ac, av);
		create_list_malloc(a);
	}
	return (0);
}
