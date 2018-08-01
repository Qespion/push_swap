/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pba_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 03:33:02 by oespion           #+#    #+#             */
/*   Updated: 2018/08/01 04:11:51 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		mov_b_tmp(t_list *mov_b, t_list *tmp_b, int total)
{
	while (mov_b != tmp_b)
	{
		mov_b = mov_b->next;
		total++;
	}
	return (total);
}

int		p_rotate(t_list **g, t_list *tmp_b, t_list *tmp_a, t_list *mov_b)
{
	int	total;

	total = 0;
	while (mov_b != tmp_b
		&& (tmp_b->nb > tmp_a->nb || tmp_b->nb < tmp_a->prev->nb))
	{
		if ((tmp_b->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
		|| (tmp_b->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
			break ;
		tmp_a = tmp_a->next;
		mov_b = mov_b->next;
		total++;
	}
	total = mov_b_tmp(mov_b, tmp_b, total);
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

int		p_rev_rotate(t_list **g, t_list *tmp_b, t_list *tmp_a, t_list *mov_b)
{
	int	total;

	total = 0;
	while (mov_b != tmp_b)
	{
		mov_b = mov_b->next;
		total++;
	}
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

t_list	**p_in_ra(t_list **g, int r)
{
	int		total;
	t_list	*tmp_b;
	t_list	*tmp_a;
	t_list	*mov_b;

	total = 0;
	mov_b = g[1];
	tmp_a = g[0];
	tmp_b = get_tmp_b(g, r);
	if (better_ra_rra(g, tmp_b))
		total = p_rotate(g, tmp_b, tmp_a, mov_b);
	else
		total = p_rev_rotate(g, tmp_b, tmp_a, mov_b);
	tmp_b->p = total;
	return (g);
}
