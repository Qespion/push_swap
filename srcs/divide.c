/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:55:01 by oespion           #+#    #+#             */
/*   Updated: 2018/06/20 16:58:02 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		upper_left(t_list *g, int mid_nb, int attribut)
{
	t_list	*tmp;

	tmp = g;
	while (tmp->next != g && tmp->p == attribut)
	{
		if (tmp->nb < mid_nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	**divide(t_list **g)
{
	int		curr_block;
	int		deep;
	int		barrier;
	int		curr_lst;
	int		median;

	curr_lst = 1;
	// OPTI == find breakpoint for best result with barrier ??
	barrier = 10;
	deep = 1;
	curr_block = ft_len_part_list(g[curr_lst], deep);
	ft_printf("curr bloc, = %d\n", curr_block);
	while (curr_block > barrier)
	{
		deep += 2;
		curr_block = ft_len_part_list(g[curr_lst], deep);
		median = real_median(g[curr_lst], deep);
		while (!upper_left(g[curr_lst], median, deep))
		{
			ft_printf("tu rentres \n");
			if (g[curr_lst]->nb < median)
			{
				g[curr_lst]->p = deep;
				curr_lst == 1 ? ft_printf("pa\n"): ft_printf("pb\n");
				g = curr_lst == 1 ?	push_a(g) : push_b(g);
			}
			else
			{
				curr_lst == 1 ? ft_printf("ra\n"): ft_printf("rb\n");
				g = curr_lst == 1 ?	rotate_a(g) : rotate_b(g);
			}
		}
		curr_lst = curr_lst == 1 ? 0 : 1;
	}
	print_list(g);
	exit(0);
	return (g);
}
