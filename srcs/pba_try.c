/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pba_try.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 04:16:27 by oespion           #+#    #+#             */
/*   Updated: 2018/08/01 04:17:30 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		mov_pbb_tmp(t_list *mov_b, t_list *tmp_b, int total)
{
	while (mov_b != tmp_b)
	{
		mov_b = mov_b->prev;
		total++;
	}
	return (total);
}

int		pbb_rotate(t_list **g, t_list *tmp_b, t_list *tmp_a, t_list *mov_b)
{
	int	total;

	total = 0;
	while (mov_b != tmp_b
		&& (tmp_b->nb > tmp_a->nb || tmp_b->nb < tmp_a->prev->nb))
	{
		if ((tmp_b->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
		|| (tmp_b->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
			break ;
		tmp_a = tmp_a->prev;
		mov_b = mov_b->prev;
		total++;
	}
	total = mov_pbb_tmp(mov_b, tmp_b, total);
	while (tmp_b->nb > tmp_a->nb || tmp_b->nb < tmp_a->prev->nb)
	{
		if ((tmp_b->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
		|| (tmp_b->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
			break ;
		tmp_a = tmp_a->prev;
		total++;
	}
	return (total);
}

int		pbb_rev_rot(t_list **g, t_list *tmp_b, t_list *tmp_a, t_list *mov_b)
{
	int	total;

	total = 0;
	while (mov_b != tmp_b)
	{
		mov_b = mov_b->prev;
		total++;
	}
	while (tmp_b->nb > tmp_a->nb || tmp_b->nb < tmp_a->prev->nb)
	{
		if ((tmp_b->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
		|| (tmp_b->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
			break ;
		tmp_a = tmp_a->next;
		total++;
	}
	return (total);
}

t_list	**p_in_rra(t_list **g, int r)
{
	int		total;
	t_list	*tmp_b;
	t_list	*tmp_a;
	t_list	*mov_b;

	total = 0;
	mov_b = g[1];
	tmp_a = g[0];
	tmp_b = get_rev_tmp_b(g, r);
	if (better_ra_rra(g, tmp_b))
		total = pbb_rev_rot(g, tmp_b, tmp_a, mov_b);
	else
		total = pbb_rotate(g, tmp_b, tmp_a, mov_b);
	tmp_b->p = total;
	return (g);
}

t_list	**iterate_elem_b(t_list **g)
{
	int		lwest_op;
	int		r;

	r = 1;
	lwest_op = get_op_base(g);
	g = set_b(g, lwest_op);
	while (r < lwest_op)
	{
		g = p_in_ra(g, r);
		r++;
	}
	r = 1;
	while (r < lwest_op + 1)
	{
		g = p_in_rra(g, r);
		r++;
	}
	return (g);
}
