/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:45 by oespion           #+#    #+#             */
/*   Updated: 2018/06/09 15:28:13 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		create_list_malloc(t_list *a)
{
	char	*str;
	int		r;
	t_list	**global;

	r = 0;
	if (!(global = (t_list**)malloc(sizeof(t_list*) * 2)))
		return (0);
	global[0] = a;
	global[1] = NULL;
	while (get_next_line(0, &str) == 1)
	{
		global = apply_checker(global, str);
		ft_strdel(&str);
	}
	ft_printf("OK\n");
	print_a(global[0]);
	free(global);
	return (0);
}

int		create_list(t_list *a)
{
	t_list	*global[2];
	char	*str;
	int		r;
	t_list	**g;

	if (!(g = (t_list**)malloc(sizeof(t_list*) * 2)))
		return (0);
	r = 0;
	global[0] = a;
	global[1] = NULL;
	g = global;
	while (get_next_line(0, &str) == 1)
	{
		//g = apply_checker(g, str);
		ft_strdel(&str);
	}
	print_a(g[0]);
	ft_printf("OK\n");
	//free(g);
	return (0);
}
