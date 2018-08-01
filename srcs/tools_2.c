/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 13:46:16 by oespion           #+#    #+#             */
/*   Updated: 2018/08/01 04:22:27 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		is_sort(t_list *lowest)
{
	t_list	*curr;

	if (!lowest)
		return (0);
	curr = lowest;
	while (curr->next != lowest)
	{
		if (curr->nb > curr->next->nb)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int		ra_or_rra(t_list **g, t_list *start_a)
{
	t_list	*cpy_0;
	int		rra;
	int		ra;

	rra = 0;
	ra = 0;
	cpy_0 = g[0];
	if (check_list(start_a))
		return (1);
	while (!((cpy_0->nb > cpy_0->next->nb && cpy_0->next->nb >= cpy_0->prev->nb
		&& cpy_0->nb <= cpy_0->next->next->nb) || (cpy_0->next->nb < cpy_0->nb
		&& cpy_0->next != start_a)))
	{
		cpy_0 = cpy_0->next;
		ra++;
	}
	cpy_0 = g[0];
	while (!((cpy_0->nb > cpy_0->next->nb && cpy_0->next->nb >= cpy_0->prev->nb
		&& cpy_0->nb <= cpy_0->next->next->nb) || (cpy_0->next->nb < cpy_0->nb
		&& cpy_0->next != start_a)))
	{
		cpy_0 = cpy_0->prev;
		rra++;
	}
	return (rra < ra ? 0 : 1);
}

t_list	*get_tmp_b(t_list **g, int r)
{
	int		i;
	t_list	*tmp_b;

	i = 1;
	tmp_b = g[1];
	while (i < r)
	{
		tmp_b = tmp_b->next;
		i++;
	}
	return (tmp_b);
}

int		ft_lst_len(t_list *lst)
{
	int		total;
	t_list	*tmp;

	total = 1;
	tmp = lst;
	while (tmp->next != lst)
	{
		total++;
		tmp = tmp->next;
	}
	return (total);
}

t_list	**swap_basic(t_list **global)
{
	t_list	*debut_a;
	int		tri;

	tri = 1;
	debut_a = global[0];
	while (tri == 1)
	{
		tri = 0;
		while (global[0]->next != debut_a)
		{
			if (global[0]->next->nb < global[0]->nb)
			{
				tri = 1;
				global = swap_a(global);
			}
			global = rotate_a(global);
		}
		global = rotate_a(global);
	}
	return (global);
}
