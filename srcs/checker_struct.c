/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:45 by oespion           #+#    #+#             */
/*   Updated: 2018/08/05 14:55:04 by oespion          ###   ########.fr       */
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
	free(global);
	return (0);
}

void	list_a_checker(t_list **g)
{
	t_list	*start;

	start = g[0];
	if (g[1] != NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	while (g[0]->next != start)
	{
		if (g[0]->nb > g[0]->next->nb)
		{
			ft_printf("KO\n");
			return ;
		}
		g[0] = g[0]->next;
	}
	ft_printf("OK\n");
}

void	create_list(t_list *a)
{
	t_list	**g;
	t_list	*start;
	char	*str;

	start = a;
	str = NULL;
	if (!(g = (t_list**)malloc(sizeof(t_list*) * 2)))
		return ;
	g[0] = a;
	g[1] = NULL;
	while (get_next_line(0, &str) == 1)
	{
		g = apply_checker(g, str);
		ft_strdel(&str);
	}
	ft_strdel(&str);
	list_a_checker(g);
	free(g);
}
