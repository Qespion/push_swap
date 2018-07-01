/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:30:44 by oespion           #+#    #+#             */
/*   Updated: 2018/07/01 12:28:59 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**sort_a(t_list **g)
{
	t_list	*start_a;

	start_a = find_lowest(g[0]);
	if (g[0]->prev->nb <= g[0]->nb && g[0]->nb > g[0]->next->nb && g[0]->next->nb >= g[0]->prev->nb)
	{
		if (g[1]->prev->nb <= g[1]->nb && g[1]->nb > g[1]->next->nb && g[1]->next->nb >= g[1]->prev->nb)
		{
			ft_printf("ss\n");
			g = swap_ss(g);
		}
		else
		{
			ft_printf("sa\n");
			g = swap_a(g);
		}
	}
	else if ((g[0]->prev->nb <= g[0]->nb || g[0] == start_a) && g[0]->nb <= g[0]->next->nb)
	{
		if ((g[1]->prev->nb <= g[1]->nb || g[1] == start_a) && g[1]->nb <= g[1]->next->nb)
		{
			ft_printf("rr\n");
			g = rotate_rr(g);
		}
		else
		{
			ft_printf("ra\n");
			g = rotate_a(g);
		}
	}
	else
	{
		ft_printf("pb\n");
		g = push_b(g);
	}
	// print_list(g);
	return (g);
}

t_list	**swap_both_list(t_list **g)
{
	// g = subdivide(g);
	// g = sort_a(g);
	while (!check_list(find_lowest(g[0])))
		g = sort_a(g);
	print_list(g);
	// exit(0);
	return (g);
}
