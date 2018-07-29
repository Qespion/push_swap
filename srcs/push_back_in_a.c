/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:00 by oespion           #+#    #+#             */
/*   Updated: 2018/07/29 12:49:29 by oespion          ###   ########.fr       */
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
	{
		while (mov_b != tmp_b && (tmp_b->nb > tmp_a->nb || tmp_b->nb < tmp_a->prev->nb))
		{
			if ((tmp_b->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
				|| (tmp_b->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
				break ;
			tmp_a = tmp_a->next;
			mov_b = mov_b->next;
			total++;
		}
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
			tmp_a = tmp_a->next;
			total++;
		}
	}
	else
	{
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
	}
	tmp_b->p = total;
	return (g);
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
	{
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
	}
	else
	{
		while (mov_b != tmp_b && (tmp_b->nb > tmp_a->nb || tmp_b->nb < tmp_a->prev->nb))
		{
			if ((tmp_b->nb > find_biggest(g[0])->nb && tmp_a == find_biggest(g[0]))
				|| (tmp_b->nb < find_lowest(g[0])->nb && tmp_a == find_lowest(g[0])))
				break ;
			tmp_a = tmp_a->prev;
			mov_b = mov_b->prev;
			total++;
		}
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
			tmp_a = tmp_a->prev;
			total++;
		}
	}
	mov_b->p = total;
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

//do the push and git push

t_list	**push_back_in_a(t_list **g)
{
	g = iterate_elem_b(g);
	print_list(g);
	exit(0);
	// g = push_lowest_elem(g);
	return (g);
}
