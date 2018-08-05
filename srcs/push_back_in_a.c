/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:00 by oespion           #+#    #+#             */
/*   Updated: 2018/08/01 05:58:17 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**ra_rrb(t_list **g, t_list *elem)
{
	while (g[1] != elem)
	{
		ft_printf("rrb\n");
		g = reverse_rotate_b(g);
	}
	while (elem->nb > g[0]->nb || elem->nb < g[0]->prev->nb)
	{
		if ((elem->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
		|| (elem->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
			break ;
		ft_printf("ra\n");
		g = rotate_a(g);
	}
	return (g);
}

t_list	**push_lowest_elem(t_list **g)
{
	t_list	*elem;

	elem = find_lowest_elem(g);
	if (ra_for_g1(g, elem))
	{
		if (better_ra_rra(g, elem))
			g = ra_rb(g, elem);
		else
			g = rra_rb(g, elem);
	}
	else
	{
		if (!better_ra_rra(g, elem))
			g = rra_rrb(g, elem);
		else
			g = ra_rrb(g, elem);
	}
	ft_printf("pa\n");
	g = push_a(g);
	return (g);
}

t_list	**push_back_in_a(t_list **g)
{
	while (g[1])
	{
		g = iterate_elem_b(g);
		g = push_lowest_elem(g);
	}
	return (g);
}
