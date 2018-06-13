/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:26:17 by oespion           #+#    #+#             */
/*   Updated: 2018/06/13 17:34:25 by oespion          ###   ########.fr       */
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

	start_a = find_lowest(g[0]);
	// print_list(g);
	//ft_printf("just before it all started \ntatatammm\n");
	while (g[0]->next != start_a)
	{
		// if (g[1] && g[0])
		// {
		// 	if (g[1]->nb <= g[0]->nb && g[1]->nb >= g[0]->prev->nb && g[0] != start_a)
		// 	{
		// 		ft_printf("pa\n");
		// 		g = push_a(g);
		// 	}
		// }
		if (g[0]->next->nb < g[0]->nb && g[0]->next->nb >= g[0]->prev->nb && g[0] != start_a)
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
		// ft_printf("iteration \n");
		else if (!check_list(start_a))
		{
			// ft_printf("just before ->\n");
			ft_printf("ra\n");
			g = rotate_a(g);
		}
		else
			break ;
		//print_list(g);
	}
	if (!check_list(start_a))
	{
		g[0]->next == start_a ?	ft_printf("ra\n") : 0;
		g[0]->next == start_a ?	g[0] = g[0]->next : 0;
		return (push_in_b(g));
	}
	return (g);
}
