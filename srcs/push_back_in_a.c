/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:00 by oespion           #+#    #+#             */
/*   Updated: 2018/06/10 15:36:13 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"


int		basic_find(t_list **g, t_list *biggest)
{
	t_list	*cpy_0;
	t_list	*cpy_1;
	int	count;

	cpy_0 = g[0];
	cpy_1 = g[1];
	count = 0;

	while (!(cpy_1->nb <= cpy_0->nb && cpy_1->nb >= cpy_0->prev->nb)
		&& !(cpy_0->prev == biggest && cpy_1->nb >= biggest->nb))
	{
		count++;
		cpy_0 = cpy_0->next;
	}
	return (count);
}

/*
int		find_better_b(t_list **g, t_list *biggest)
{
	t_list	*stock_b;
	t_list	*stock_a;
	int		count;

	count = basic_find(g, biggest);
	stock_b = g[1];
	stock_a = g[0];
	if (better_in_reverse(g, count))
	{

	}
}*/

t_list	**push_back_in_a(t_list **g)
{
	t_list	*start_a;
	t_list	*current_a;
	t_list	*biggest;

	current_a = g[0];
	start_a = find_lowest(g[0]);
	while (g[1] != NULL)
	{
		// ft_printf("rotation = %d\n", basic_find(g, biggest));
		biggest = find_biggest(g[0]);
		if (g[1]->nb <= g[0]->nb && g[1]->nb >= g[0]->prev->nb)
		{
			push_a(g);
			ft_printf("pa\n");
		}
		else if (g[0]->prev == biggest && g[1]->nb >= biggest->nb)
		{
			push_a(g);
			ft_printf("pa\n");
		}
		else if (better_in_rrr(g, basic_find(g, biggest), biggest))
		{
			reverse_rotate_rr(g);
			ft_printf("rrr\n");
		}
		else if (better_in_reverse_ra(g, basic_find(g, biggest), biggest))
		{
			reverse_rotate_a(g);
			ft_printf("rra\n");
		}
		// else if (better_in_reverse_rb(g, basic_find(g, biggest), biggest))
		// {
		// 	reverse_rotate_a(g);
			//ft_printf("rrb\n");
		// }
		else
		{
			rotate_a(g);
			ft_printf("ra\n");
		}
	}
	return (g);
}
