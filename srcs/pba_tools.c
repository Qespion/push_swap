/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pba_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 01:40:27 by oespion           #+#    #+#             */
/*   Updated: 2018/08/01 03:22:53 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		get_op_base(t_list **g)
{
	int		ra;
	int		rra;
	t_list	*tmp_a;

	ra = 0;
	rra = 0;
	tmp_a = g[0];
	while (g[1]->nb > tmp_a->nb || g[1]->nb < tmp_a->prev->nb)
	{
		if ((g[1]->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
			|| (g[1]->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
			break ;
		ra++;
		tmp_a = tmp_a->next;
	}
	tmp_a = g[0];
	while (g[1]->nb > tmp_a->nb || g[1]->nb < tmp_a->prev->nb)
	{
		if ((g[1]->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
			|| (g[1]->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
			break ;
		rra++;
		tmp_a = tmp_a->prev;
	}
	return (ra <= rra ? ra : rra);
}

t_list	**set_b(t_list **g, int lowest)
{
	t_list	*tmp;

	g[1]->p = lowest;
	tmp = g[1]->next;
	while (tmp != g[1])
	{
		tmp->p = lowest + 1;
		tmp = tmp->next;
	}
	return (g);
}

t_list	*get_rev_tmp_b(t_list **g, int r)
{
	int		i;
	t_list	*tmp_b;

	i = 1;
	tmp_b = g[1];
	while (i < r)
	{
		tmp_b = tmp_b->prev;
		i++;
	}
	return (tmp_b);
}

int		better_ra_rra(t_list **g, t_list *tmp_b)
{
	int		ra;
	int		rra;
	t_list	*tmp_a;

	ra = 0;
	rra = 0;
	tmp_a = g[0];
	while (tmp_b->nb > tmp_a->nb || tmp_b->nb < tmp_a->prev->nb)
	{
		if ((tmp_b->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
		|| (tmp_b->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
			break ;
		ra++;
		tmp_a = tmp_a->next;
	}
	tmp_a = g[0];
	while (tmp_b->nb > tmp_a->nb || tmp_b->nb < tmp_a->prev->nb)
	{
		if ((tmp_b->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
		|| (tmp_b->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
			break ;
		rra++;
		tmp_a = tmp_a->prev;
	}
	return (ra <= rra ? 1 : 0);
}
