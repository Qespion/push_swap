/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:26:17 by oespion           #+#    #+#             */
/*   Updated: 2018/06/07 17:40:15 by oespion          ###   ########.fr       */
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

	start_a = g[0];
	while (g[0]->next != start_a)
	{
		if (g[0]->next->nb < g[0]->nb && g[0]->next->nb >= g[0]->prev->nb)
		{
			if (g[1])
			{
				g[1]->next->nb < g[1]->nb ? ft_printf("ss\n") : ft_printf("sa\n");
				g = g[1]->next->nb < g[1]->nb ? swap_ss(g) : swap_a(g);
			}
			else
			{
				ft_printf("sa\n");
				swap_a(g);
			}
		}
		else if (g[0]->next->nb < g[0]->nb && g[0]->next != start_a)
		{
			if (g[0] == start_a)
				start_a = g[0]->next;
			ft_printf("pb\n");
			g = push_b(g);
		}
		//ft_printf("iteration \n");
		//print_list(g);
		ft_printf("ra\n");
		g = rotate_a(g);
	}
	ft_printf("ra\n");
	g = rotate_a(g);
	if (!check_list(g[0]))
		push_in_b(g);
	return (g);
}