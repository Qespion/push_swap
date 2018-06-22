/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:32:16 by oespion           #+#    #+#             */
/*   Updated: 2018/06/22 14:20:18 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_poz	*best_starting_pos(t_list *a, t_poz *best_start, t_list *tmp)
{
	int	total;
	t_list	*lst;
	t_list	*start;

	start = a;
	lst = a->next;
	total = 1;
	while (lst->next != a)
	{
		if (lst->nb < lst->prev->nb && lst->next->nb < lst->prev->nb)
			break ;
		if (lst->nb < lst->prev->nb && lst->next->nb >= lst->prev->nb)
		{
			total++;
			lst = lst->next;
			if (lst->prev > lst->next)
				break ;
		}
		if (lst->nb <= lst->next->nb)
		{
			total++;
			lst = lst->next;
		}
	}
	if (total > best_start->len)
	{
		best_start->len = total;
		best_start->starting = start;
	}
	return (best_start);
}
