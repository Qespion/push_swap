/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:26:17 by oespion           #+#    #+#             */
/*   Updated: 2018/06/23 11:38:49 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		check_list(t_list *start)
{
	t_list	*lst;

	lst = start;
	while (lst->next != start)
	{
		if (lst->next->nb < lst->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	**push_in_b(t_list **g)
{
	t_list	*start_a;
	t_list	*biggest;
	t_list	*start_b;

	start_a = find_lowest(g[0]);
	biggest = find_biggest(g[0]);
	start_b = find_lowest(g[1]);
	if (g[0]->nb > g[0]->next->nb && g[0]->next->nb >= g[0]->prev->nb)
	{
		if (g[1])
		{
			g[1]->next->nb < g[1]->nb ? ft_printf("ss\n") : ft_printf("sa\n");
			g = g[1]->next->nb < g[1]->nb ? swap_ss(g) : swap_a(g);
		}
		else
		{
			ft_printf("sa\n");
			g = swap_a(g);
		}
	}
	else if (g[0]->next->nb < g[0]->nb && g[0]->next != start_a)
	{
		if (g[0] == start_a)
			start_a = g[0]->next;
		ft_printf("pb\n");
		g = push_b(g);
	}
	if (!ra_or_rra(g, start_a))
	{
		while (!((g[0]->nb > g[0]->next->nb && g[0]->next->nb >= g[0]->prev->nb)
		|| (g[0]->next->nb < g[0]->nb && g[0]->next != start_a)))
		{
			g = reverse_rotate_a(g);
			ft_printf("rra\n");
		}
		if (g[0]->nb > g[0]->next->nb && g[0]->next->nb >= g[0]->prev->nb)
		{
			if (g[1])
			{
				g[1]->next->nb < g[1]->nb ? ft_printf("ss\n") : ft_printf("sa\n");
				g = g[1]->next->nb < g[1]->nb ? swap_ss(g) : swap_a(g);
			}
			else
			{
				ft_printf("sa\n");
				g = swap_a(g);
			}
		}
		else if (g[0]->next->nb < g[0]->nb && g[0]->next != start_a)
		{
			if (g[0] == start_a)
				start_a = g[0]->next;
			ft_printf("pb\n");
			g = push_b(g);
		}
	}
	else if (!check_list(start_a))
	{
		while (!((g[0]->nb > g[0]->next->nb && g[0]->next->nb >= g[0]->prev->nb)
		|| (g[0]->next->nb < g[0]->nb && g[0]->next != start_a)))
		{
			if (g[1])
			{
				if (!((g[1]->nb > g[1]->next->nb && g[1]->next->nb >= g[1]->prev->nb)
					|| (g[1]->next->nb < g[1]->nb && g[1]->next != start_b)))
				{
					g = rotate_rr(g);
					ft_printf("rr\n");
				}
				else
				{
					g = rotate_a(g);
					ft_printf("ra\n");
				}
			}
			else
			{
				g = rotate_a(g);
				ft_printf("ra\n");
			}
		}
		if (g[0]->nb > g[0]->next->nb && g[0]->next->nb >= g[0]->prev->nb)
		{
			if (g[1])
			{
				g[1]->next->nb < g[1]->nb ? ft_printf("ss\n") : ft_printf("sa\n");
				g = g[1]->next->nb < g[1]->nb ? swap_ss(g) : swap_a(g);
			}
			else
			{
				ft_printf("sa\n");
				g = swap_a(g);
			}
		}
		else if (g[0]->next->nb < g[0]->nb && g[0]->next != start_a)
		{
			if (g[0] == start_a)
				start_a = g[0]->next;
			ft_printf("pb\n");
			g = push_b(g);
		}
	}
	// print_list(g);
	start_a = find_lowest(g[0]);
	if (!check_list(start_a))
		return (push_in_b(g));
	return (g);
}