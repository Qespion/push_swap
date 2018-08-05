/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:30:44 by oespion           #+#    #+#             */
/*   Updated: 2018/08/05 14:54:00 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		in_order(t_list *start)
{
	t_list	*tmp;

	tmp = start;
	while (tmp->nb <= tmp->next->nb && tmp->next != start)
		tmp = tmp->next;
	return (tmp->next == start ? 1 : 0);
}

int		swap_ra_rra(t_list **g)
{
	int		ra;
	int		rra;
	t_list	*tmp_a;

	ra = 0;
	rra = 0;
	tmp_a = g[0];
	while (tmp_a->nb < tmp_a->next->nb || tmp_a->next == find_lowest(g[0]))
	{
		tmp_a = tmp_a->next;
		ra++;
	}
	tmp_a = g[0];
	while (tmp_a->nb > tmp_a->prev->nb || tmp_a == find_lowest(g[0]))
	{
		tmp_a = tmp_a->prev;
		rra++;
	}
	return (ra <= rra ? 1 : 0);
}

t_list	**swap_both_next(t_list **g)
{
	if (swap_ra_rra(g))
	{
		ft_printf("ra\n");
		g = rotate_a(g);
	}
	else if (!swap_ra_rra(g) && (g[1]->nb > g[1]->prev->nb
	|| g[1] == find_lowest(g[0])))
	{
		ft_printf("rrr\n");
		g = reverse_rotate_rr(g);
	}
	else
	{
		ft_printf("rra\n");
		g = reverse_rotate_a(g);
	}
	return (g);
}

t_list	**swap_both_list(t_list **g)
{
	while (!in_order(find_lowest(g[0])))
	{
		if (g[0]->nb > g[0]->next->nb && g[1]->nb > g[1]->next->nb
		&& g[0]->next != find_lowest(g[0]) && g[1]->next != find_lowest(g[1])
		&& g[0]->next->nb > g[0]->prev->nb)
		{
			ft_printf("ss\n");
			g = swap_ss(g);
		}
		else if (g[0]->nb > g[0]->next->nb && g[0]->next != find_lowest(g[0])
		&& g[0]->next != find_lowest(g[0]))
		{
			ft_printf("sa\n");
			g = swap_a(g);
		}
		else if (swap_ra_rra(g) && (g[1]->nb < g[1]->next->nb
		|| g[1]->next == find_lowest(g[1])))
		{
			ft_printf("rr\n");
			g = rotate_rr(g);
		}
		else
			g = swap_both_next(g);
	}
	return (g);
}

void	ft_error(t_list *a)
{
	ft_lstdel(a);
	ft_putstr_fd("Error\n", 2);
}
