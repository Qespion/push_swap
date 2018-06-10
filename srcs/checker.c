/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:49:40 by oespion           #+#    #+#             */
/*   Updated: 2018/06/10 16:33:24 by oespion          ###   ########.fr       */
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
	int		visu;

	visu = 1;
	!strcmp(av[1], "-v") ? visu = 2 : 0;
	if (ac < 2)
		return (1);
	fd = open(av[visu], 0);
	if (visu == 2)
	{
		ft_printf("test\n");
	}
	if (get_next_line(fd, &str) == 1)
	{
		a = create_a_from_str(str);
		create_list(a);
		ft_strdel(&str);
	}
	else
	{
		a = create_a(ac, av);
		create_list(a);
	}
	return (0);
}
