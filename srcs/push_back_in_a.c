/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:00 by oespion           #+#    #+#             */
/*   Updated: 2018/07/12 17:29:32 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**reset_p(t_list **g)
{
	t_list	*tmp;

	tmp = g[1];
	while (tmp->next != g[1])
	{
		tmp->p = -1;
		tmp = tmp->next;
	}
	tmp->p = -1;
	return (g);
}


int		basic_find(t_list **g, t_list *biggest)
{
	t_list	*cpy_0;
	t_list	*cpy_1;
	int	count;

	cpy_0 = g[0];
	cpy_1 = g[1];
	count = 0;

	while (!(cpy_1->nb <= cpy_0->nb && cpy_1->nb >= cpy_0->prev->nb)
		&& !(cpy_0->prev == biggest && cpy_1->nb >= biggest->nb))
	{
		count++;
		cpy_0 = cpy_0->next;
	}
	return (count);
}

/*
**	Faire un tab qui va stock le nb d'action du plus simple au plus complexe
**	-with ra/rra
**	-with rb/rrb
**	-with a rb find is place with ra /rra
** 	-with a ra blahblaj blha with rb /rrb
**	*most fun* With rrr or rr and some ra/rb/rrb/rra *most FUN*
**	find lowest
**	do
*/

// int		get_op_for_b(t_list **g)
// {
// 	int	operation;
// 	int	tmp_op;
// 	t_list	*start;
// 	t_list	*tmp_a;

// 	tmp_op = 0;
// 	operation = 0;
// 	tmp_a = g[0];
// 	start = find_lowest(g[0]);
// 	while ((g[1]->nb > tmp_a->nb || tmp_a == start) && g[1]->prev->nb < tmp_a->nb)
// 	{
// 		operation++;
// 		tmp_a = tmp_a->next;
// 	}
// 	tmp_a = g[0];
// 	while ((g[1]->nb > tmp_a->nb || tmp_a == start) && g[1]->prev->nb < tmp_a->nb)
// 	{
// 		tmp_op++;
// 		tmp_a = tmp_a->prev;
// 	}
// 	// print_list(g);
// 	// ft_printf("operation = %d\n", operation);
// 	return operation < tmp_op ? operation : tmp_op;
// }

// int		check_at_b(t_list **g, int r)
// {
// 	int		total;
// 	t_list	*tmp;
// 	t_list	**g_tmp;
// 	int		i;

// 	i = 0;
// 	g_tmp = g;
// 	while(i < r)
// 	{
// 		g_tmp[1] = g_tmp[1]->next;
// 		i++;
// 	}
// 	tmp = g[0];
// 	if (ra_or_rra(g, find_lowest(g[0])))
// 	{
// 		total = r;
// 		while (g_tmp[0]->prev->nb > g[1]->nb || g_tmp[0]->nb < g[1]->nb)
// 		{
// 			g_tmp[0] = g_tmp[0]->prev;
// 			total++;
// 		}
// 		return (total);
// 	}
// 	total = 0;
// 	while (g_tmp[0]->prev->nb > g[1]->nb || g_tmp[0]->nb < g[1]->nb)
// 	{
// 		g_tmp[0] = g_tmp[0]->next;
// 		if (r > 0)
// 			r--;
// 		else
// 			total++;
// 	}
// 	return (total);
// }

// t_list	**calc_moves(t_list **g, int len, int pos)
// {
// 	t_list	*tmp_a;
// 	int		moves;

// 	moves = 0;
// 	tmp_a = g[0];
// 	if (pos < len / 2)
// 	{
// 		if (ra_or_rra(g, find_lowest(g[0])))
// 		{
// 			while (g[1]->nb > g[0]->nb && g[0]->next != find_lowest(g[0]))
// 			{
// 				moves++;
// 				g[0] = g[0]->next;
// 			}
// 			if (moves < pos)
// 				moves = pos;
// 		}
// 		else
// 		{
// 			moves = pos;
// 			while (g[1]->nb < g[0]->prev->nb && g[0] != find_lowest(g[0]))
// 			{
// 				moves++;
// 				g[0] = g[0]->prev;
// 			}
// 		}
// 	}
// 	else
// 	{
// 		if (ra_or_rra(g, find_lowest(g[0])))
// 		{
// 			moves = pos;
// 			while (g[1]->nb > g[0]->nb && g[0]->next != find_lowest(g[0]))
// 			{
// 				moves++;
// 				g[0] = g[0]->next;
// 			}
// 		}
// 		else
// 		{
// 			while (g[1]->nb < g[0]->prev->nb && g[0] != find_lowest(g[0]))
// 			{
// 				moves++;
// 				g[0] = g[0]->prev;
// 			}
// 			if (moves < pos)
// 				moves = pos;
// 		}
// 	}
// 	g[0] = tmp_a;
// 	g[1]->p = moves;
// 	return (g);
// }

// t_list	**get_mov_b(t_list **g)
// {
// 	t_list	*start_b;
// 	int		len;
// 	int		pos;

// 	pos = 0;
// 	len = ft_len_list(g[1]);
// 	start_b = g[1];
// 	while (g[1]->next != start_b)
// 	{
// 		g = calc_moves(g, len, pos);
// 		g[1] = g[1]->next;
// 		pos++;
// 	}
// 	g[1] = start_b;
// 	return (g);
// }

// t_list	*lowest_move_b(t_list *lst)
// {
// 	t_list	*lowest;
// 	t_list	*tmp;

// 	tmp = lst;
// 	lowest = lst;
// 	while (tmp->next != lst)
// 	{
// 		if (tmp->p < lowest->p)
// 			lowest = tmp;
// 		tmp = tmp->next;
// 	}
// 	if (tmp->p < lowest->p)
// 			lowest = tmp;
// 	return (lowest);
// }

// t_list	**operate_b(t_list **g)
// {
// 	t_list	*lowest;
// 	t_list	*tmp_b;

// 	tmp_b = g[1];
// 	lowest = lowest_move_b(g[1]);
// 	if (rb_or_rrb(g, lowest))
// 	{
// 		if (place_in_ra(g, lowest))
// 		{
// 			while (g[1] != lowest && g[1]->nb > g[0]->nb && g[0]->nb != find_lowest(g[0]))
// 			{
// 				ft_printf("rr\n");
// 				g = rotate_rr(g);
// 			}
// 			while (g[1] != lowest)
// 			{
// 				ft_printf("rb\n");
// 				g = rotate_b(g);
// 			}
// 			while (g[1]->nb > g[0]->nb && g[0]->nb != find_lowest(g[0]))
// 			{
// 				ft_printf("ra\n");
// 				g = rotate_a(g);
// 			}
// 			ft_printf("pa\n");
// 			g = push_a(g);
// 		}
// 		else
// 		{
// 			while (g[1] != lowest)
// 			{
// 				ft_printf("rb")
// 				g = reverse_rotate_b(g);
// 			}
// 			while (g[1]->nb < g[0]->prev->nb && g[0]->nb != find_biggest(g[0]))
// 			{
// 				ft_printf("rra\n");
// 				g = reverse_rotate_a(g);
// 			}
// 			ft_printf("pa\n");
// 			g = push_a(g);
// 		}
// 	}
// 	else
// 	{
// 		if (place_in_ra(g, lowest))
// 		{
// 			while (g[1] != lowest)
// 			{
// 				ft_printf("rrb\n");
// 				g = reverse_rotate_b(g);
// 			}
// 			while (g[1]->nb > g[0]->nb && g[0]->nb != find_lowest(g[0]))
// 			{
// 				ft_printf("ra\n");
// 				g = rotate_a(g);
// 			}
// 			ft_printf("pa\n");
// 			g = push_a(g);
// 		}
// 		else
// 		{
// 			while (g[1] != lowest && g[1]->nb > g[0]->nb && g[0]->nb != find_lowest(g[0]))
// 			{
// 				ft_printf("rrr\n");
// 				g = reverse_rotate_rr(g);
// 			}
// 			while (g[1] != lowest)
// 			{
// 				ft_printf("rb");
// 				g = reverse_rotate_b(g);
// 			}
// 			while (g[1]->nb < g[0]->prev->nb && g[0]->nb != find_biggest(g[0]))
// 			{
// 				ft_printf("rra\n");
// 				g = reverse_rotate_a(g);
// 			}
// 			ft_printf("pa\n");
// 			g = push_a(g);
// 		}
// 	}
// 	return (g);
// }

// t_list	**push_back_in_a(t_list **g)
// {
// 	while (g[1] != NULL)
// 	{
// 		g = get_mov_b(g);
// 		g = operate_b(g);
// 	}
// 	return (g);
// }

// ----------------------------------

t_list	**find_other_opt(t_list **g, t_list *biggest)
{
	int	tab[5];
	int	lowest;
	t_list	**curr;
	int		gap_len;

	tab[0] = calc_ra(g, biggest);
	tab[1] = calc_rra(g, biggest);
	lowest = tab[1] < tab[0] ? tab[1] : tab[0];
	gap_len = 0;
	curr = g;
	while (gap_len < lowest)
	{
		curr[1] = curr[1]->next;
		gap_len++;
		if (calc_other_rb(curr, lowest, biggest, gap_len) < lowest)
		{
			do_op(g, gap_len, calc_other_rb(curr, lowest, biggest, gap_len));
			return (g);
		}
	}
	curr = g;
	gap_len = 0;
	while (gap_len < lowest)
	{
		curr[1] = curr[1]->prev;
		gap_len++;
		if (calc_other_rb(curr, lowest, biggest, gap_len * -1) < lowest)
		{
			do_op(g, gap_len * -1, calc_other_rb(curr, lowest, biggest, gap_len));
			return (g);
		}
	}
	return (g);
}

t_list	**push_back_in_a(t_list **g)
{
	t_list	*start_a;
	t_list	*current_a;
	t_list	*biggest;

	current_a = g[0];
	while (g[1] != NULL)
	{
		start_a = find_lowest(g[0]);
		biggest = find_biggest(g[0]);
		if (g[1]->nb <= g[0]->nb && g[1]->nb >= g[0]->prev->nb)
		{
			push_a(g);
			ft_printf("pa\n");
		}
		else if (g[0]->prev == biggest && g[1]->nb >= biggest->nb)
		{
			push_a(g);
			ft_printf("pa\n");
		}
		else if (g[1]->nb < start_a->nb)
		{
			rotate_to_lower(g);
			push_a(g);
			ft_printf("pa\n");
		}
		else if (better_in_reverse_ra(g, basic_find(g, biggest), biggest))
		{
			reverse_rotate_a(g);
			ft_printf("rra\n");
		}
		else
		{
			g = rotate_a(g);
			ft_printf("ra\n");
		}
	}
	return (g);
}
