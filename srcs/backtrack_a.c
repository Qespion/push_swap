/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:32:16 by oespion           #+#    #+#             */
/*   Updated: 2018/06/24 11:18:06 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_poz	*best_starting_pos(t_poz *best_start, t_list *tmp)
{
	int	curr_nb;
	int	total;
	t_list	*lst;

	lst = tmp->next;
	total = 1;
	curr_nb = tmp->nb;
	while (lst->next != tmp)
	{
		if (curr_nb <= lst->nb)
		{
			best_start->ending = lst;
			curr_nb = lst->nb;
			total += 1;
			lst = lst->next;
		}
		else if (curr_nb > lst->nb && curr_nb <= lst->next->nb && lst->nb >= lst->next->nb)
		{
			best_start->ending = lst;
			total += 2;
			lst = lst->next->next;
		}
		else if (curr_nb > lst->nb)
			lst = lst->next;
	}
	if (total > best_start->len)
	{
		best_start->len = total;
		best_start->starting = tmp;
	}
	return (best_start);
}

t_list	**go_to_starting_pos(t_poz *best_start, t_list **g)
{
	t_list	*tmp;
	int		ra;
	int		rra;
	int		ending;

	ending = 0;
	ra = 0;
	rra = 0;
	tmp = g[0];
	while (tmp != best_start->starting)
	{
		if (tmp == best_start->ending)
		{
			while (g[0] != best_start->ending)
			{
				g = rotate_a(g);
				ft_printf("ra\n");
			}
		}
		tmp = tmp->next;
	}
	while (g[0] != best_start->starting)
	{
		g = push_b(g);
		ft_printf("pb\n");
	}
	return (g);
}
