/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:49:40 by oespion           #+#    #+#             */
/*   Updated: 2018/07/24 14:25:20 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

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
			{
				ft_lstdel(a);
				exit(-1);
			}
			str++;
		}
	}
	return (start);
}

t_list	*creat_a(int ac, char **av)
{
	t_list	*a;
	t_list	*start;
	int		r;

	r = 2;
	if (ac > 1)
	{
		if (!(a = ft_lstnew(ft_atoi(av[1]))))
			exit(-1);
		start = a;
	}
	while (r < ac)
	{
		if (!(a = ft_lstaddone(ft_atoi(av[r]), start, a)))
		{
			ft_lstdel(a);
			exit(-1);
		}
		r++;
	}
	return (start);
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

int		main(int ac, char **av)
{
	t_list	*a;
	char	*str;
	int		fd;
	int		r;

	if (ac < 2)
		return (1);
	fd = open(av[1], 0);
	if (get_next_line(fd, &str) == 1)
	{
		a = create_a_from_str(str);
		r = checker_str(str);
		ft_strdel(&str);
	}
	else
	{
		a = creat_a(ac, av);
		r = check_a(ac, av);
	}
	r == 1 ? r = check_doublon(a) : 0;
	r == 0 ? ft_putstr_fd("Error\n", 2) : create_list(a);
	return (r == 0 ? 1 : 0);
}
