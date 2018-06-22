/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:26:17 by oespion           #+#    #+#             */
/*   Updated: 2018/06/22 14:33:20 by oespion          ###   ########.fr       */
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
	t_poz	*best_start;
	t_list	*tmp;

	tmp = g[0];
	if (!(best_start = (t_poz*)malloc(sizeof(t_poz))))
		return (NULL);
	best_start->starting = g[0];
	best_start->len = 0;
	while (tmp->next != g[0])
	{
		best_start = best_starting_pos(g[0],best_start, tmp);
		tmp = tmp->next;
	}
	return (g);
}
