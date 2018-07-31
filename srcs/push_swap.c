/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:40:59 by oespion           #+#    #+#             */
/*   Updated: 2018/07/31 23:43:35 by oespion          ###   ########.fr       */
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

t_list	*create_a(int ac, char **av, int teube)
{
	t_list	*a;
	t_list	*start;
	int		r;

	r = 2;
	if (ac > 1 && teube == 0)
	{
		if (!(a = ft_lstnew(ft_atoi(av[1]))))
			exit(-1);
		start = a;
	}
	if (teube == 1 && ac > 1)
	{
		if (!(a = ft_lstnew(ft_atoi(av[r]))))
			exit(-1);
		start = a;
		r++;
	}
	while (r < ac)
	{
		if (!(a = ft_lstaddone(ft_atoi(av[r]), start, a)))
			exit(-1);
		r++;
	}
	return (start);
}

t_list	*create_a_from_str(char *str)
{
	t_list	*a;
	t_list	*start;

	if (!(a = ft_lstnew(ft_atoi(str))))
		exit(-1);
	start = a;
	while (*str)
	{
		while (*str != ' ' && *str)
			str++;
		if (*str == ' ' && str[1] != '\0')
		{
			if (!(a = ft_lstaddone(ft_atoi(str), start, a)))
				exit(-1);
			str++;
		}
	}
	return (start);
}

int		main(int ac, char **av)
{
	t_list	*a;
	char	*str;
	int		fd;
	int		r;
	int		teube;

	teube = 0;
	r = 1;
	if (ac < 2)
		return (1);
	!ft_strcmp("-R", av[1]) ? teube = 1 : 0;
	fd = open(av[teube == 1 ? 2 : 1], 0);
	if (get_next_line(fd, &str) == 1)
	{
		a = create_a_from_str(str);
		r = checker_str(str);
	}
	else
	{
		a = create_a(ac, av, teube);
		r = check_a(ac, av);
		ft_pustr("str");
	}
	r == 1 ? r = check_doublon(a) : 0;
	r == 0 ? ft_putstr_fd("Error\n", 2) : solver(a, teube);
	return (r == 0 ? 1 : 0);
}
