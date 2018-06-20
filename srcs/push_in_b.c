/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:26:17 by oespion           #+#    #+#             */
/*   Updated: 2018/06/20 17:03:00 by oespion          ###   ########.fr       */
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

int		upper_mid_left(t_list **g, int mid_nb)
{
	t_list	*tmp;

	tmp = g[0];
	while (tmp->next != g[0])
	{
		if (tmp->nb < mid_nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
**	get upper half in b
**	start sort a
*/

t_list	**push_in_b(t_list **g)
{
	t_list	*start;
	int		median;

	median = real_median(g[0], 0);
	start = g[0];
	while (!upper_mid_left(g, median))
	{
		if (g[0]->nb < median)
		{
			g = push_b(g);
			g[1]->p = 1;
			ft_printf("pb\n");
		}
		else
		{
			// A OPTI > SA||SS<
			g = rotate_a(g);
			ft_printf("ra\n");
		}
	}
	// print_list(g);
	// exit(0);
	return (g);
}
