/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:49:40 by oespion           #+#    #+#             */
/*   Updated: 2018/08/16 17:21:27 by oespion          ###   ########.fr       */
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
				exit(-1);
			str++;
		}
	}
	return (start);
}

t_list	*find_next(char *str, t_list *start, t_list *a)
{
	while ((*str >= '0' && *str <= '9') || *str == '-')
		str++;
	if (*str == ' ')
		str++;
	while (*str)
	{
		if (*str == '-')
			break ;
		if (!(a = ft_lstaddone(ft_atoi(str), start, a)))
			exit(-1);
		while ((*str >= '0' && *str <= '9') || *str == '-')
			str++;
		if (*str == ' ')
			str++;
		if ((*str < '0' || *str > '9') && *str != ' ' && *str != '-' && *str != '\0')
			return (a);
	}
	return (a);
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
		a = find_next(av[1], start, a);
	}
	while (r < ac)
	{
		if (!(a = ft_lstaddone(ft_atoi(av[r]), start, a)))
			exit(-1);
		a = find_next(av[r], start, a);
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
	if (a)
		ft_lstdel(a);
	return (r == 0 ? 1 : 0);
}
