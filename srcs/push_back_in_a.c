/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:00 by oespion           #+#    #+#             */
/*   Updated: 2018/06/19 19:08:52 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"


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
	start_a = find_lowest(g[0]);
	while (g[1] != NULL)
	{
		biggest = find_biggest(g[0]);
		if (g[1]->nb <= g[0]->nb && g[1]->nb >= g[0]->prev->nb)
		{
			push_a(g);
			ft_printf("pa\n");
			find_other_opt(g, biggest);
		}
		else if (g[0]->prev == biggest && g[1]->nb >= biggest->nb)
		{
			push_a(g);
			ft_printf("pa\n");
			find_other_opt(g, biggest);
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
