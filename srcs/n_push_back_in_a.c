/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_push_back_in_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:54:26 by oespion           #+#    #+#             */
/*   Updated: 2018/07/12 17:25:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**calc_moves(t_list **g, int len, int pos)
{
	int		mov1;
	t_list	*tmp;
	int		mov2;

	mov2 = 0;
	mov1 = 0;
	tmp = g[0];
	if (pos < len / 2)
	{
		mov2 = pos;
		while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
		{
			tmp = tmp->next;
			if ((g[1]->nb > find_biggest(tmp)->nb && tmp == find_biggest(tmp))
				|| (g[1]->nb < find_lowest(tmp)->nb && tmp == find_lowest(tmp)))
				break ;
			mov1++;
		}
		tmp = g[0];
		while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
		{
			tmp = tmp->prev;
			if ((g[1]->nb > find_biggest(tmp)->nb && tmp == find_biggest(tmp))
				|| (g[1]->nb < find_lowest(tmp)->nb && tmp == find_lowest(tmp)))
				break ;
			mov2++;
		}
	}
	else
	{
		mov1 = pos;
		while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
		{
			tmp = tmp->next;
			if ((g[1]->nb > find_biggest(tmp)->nb && tmp == find_biggest(tmp))
				|| (g[1]->nb < find_lowest(tmp)->nb && tmp == find_lowest(tmp)))
				break ;
			mov1++;
		}
		tmp = g[0];
		while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
		{
			tmp = tmp->prev;
			if ((g[1]->nb > find_biggest(tmp)->nb && tmp == find_biggest(tmp))
				|| (g[1]->nb < find_lowest(tmp)->nb && tmp == find_lowest(tmp)))
				break ;
			mov2++;
		}
		if (mov2 < len - pos)
			mov2 = len - pos;
	}
	g[1]->p = mov1 < mov2 ? mov1 : mov2;
	return (g);
}

t_list	**get_mov_b(t_list **g)
{
	int		len;
	int		pos;
	t_list	*start_b;

	pos = 0;
	len = ft_len_list(g[1]);
	start_b = g[1];
	while (g[1]->next != start_b)
	{
		g = calc_moves(g, len, pos);
		g[1] = g[1]->next;
		pos++;
	}
	g[1] = start_b;
	return (g);
}

t_list	*get_lowest_in_b(t_list **g)
{
	int		lowest;
	t_list	*move_b;
	t_list	*tmp;

	tmp = g[1];
	lowest = g[1]->p;
	move_b = g[1];
	while (tmp->next != g[1])
	{
		if (tmp->p < lowest)
		{
			lowest = tmp->p;
			move_b = tmp;
		}
		tmp = tmp->next;
	}
	if (tmp->p < lowest)
			move_b = tmp;
	return (move_b);
}

int		rb_rrb(t_list **g, t_list *mb)
{
	int		rb;
	int		rrb;
	t_list	*tmp;

	rb = 0;
	rrb = 0;
	tmp = g[1];
	while (tmp != mb)
	{
		tmp = tmp->next;
		rb++;
	}
	tmp = g[1];
	while (tmp != mb)
	{
		tmp = tmp->prev;
		rrb++;
	}
	return (rb < rrb ? 1 : 0);
}

int		ra_rra(t_list **g, t_list *mb)
{
	int		ra;
	int		rra;
	t_list	*tmp;

	ra = 0;
	rra = 0;
	tmp = g[0];
	while (mb->nb > tmp->nb || mb->nb < tmp->prev->nb)
	{
		tmp = tmp->next;
		ra++;
		if ((mb->nb > find_biggest(tmp)->nb && tmp == find_biggest(tmp))
				|| (mb->nb < find_lowest(tmp)->nb && tmp == find_lowest(tmp)))
				break ;
	}
	tmp = g[0];
	while (mb->nb > tmp->nb || mb->nb < tmp->prev->nb)
	{
		tmp = tmp->next;
		rra++;
		if ((mb->nb > find_biggest(tmp)->nb && tmp == find_biggest(tmp))
				|| (mb->nb < find_lowest(tmp)->nb && tmp == find_lowest(tmp)))
				break ;
	}
	return (ra < rra ? 1 : 0);
}

t_list	**move_lowest(t_list **g)
{
	t_list	*move_b;

	move_b = get_lowest_in_b(g);
	if (rb_rrb(g, move_b))
	{
		if (ra_rra(g, move_b))
		{
			while (g[1] != move_b)
			{
				ft_printf("rb\n");
				g = rotate_b(g);
			}
			while (g[1]->nb > g[0]->nb || g[1]->nb < g[0]->prev->nb)
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
						|| (g[1]->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
						break ;
				ft_printf("ra\n");
				g = rotate_a(g);
			}
			ft_printf("pa\n");
			g = push_a(g);
		}
		else
		{
			while (g[1] != move_b)
			{
				ft_printf("rb\n");
				g = rotate_b(g);
			}
			while (g[1]->nb > g[0]->nb || g[1]->nb < g[0]->prev->nb)
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
						|| (g[1]->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
						break ;
				ft_printf("rra\n");
				g = rotate_a(g);
			}
			ft_printf("pa\n");
			g = push_a(g);
		}
	}
	else
	{
		if (ra_rra(g, move_b))
		{
			while (g[1] != move_b)
			{
				ft_printf("rrb\n");
				g = rotate_b(g);
			}
			while (g[1]->nb > g[0]->nb || g[1]->nb < g[0]->prev->nb)
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
						|| (g[1]->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
						break ;
				ft_printf("ra\n");
				g = rotate_a(g);
			}
			ft_printf("pa\n");
			g = push_a(g);
		}
		else
		{
			while (g[1] != move_b)
			{
				ft_printf("rrb\n");
				g = rotate_b(g);
			}
			while (g[1]->nb > g[0]->nb || g[1]->nb < g[0]->prev->nb)
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
						|| (g[1]->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
						break ;
				ft_printf("rra\n");
				g = rotate_a(g);
			}
			ft_printf("pa\n");
			g = push_a(g);
		}
	}
	return (g);
}

t_list	**n_push_back_in_a(t_list **g)
{
	while (g[1] != NULL)
	{
		g = get_mov_b(g);
		// print_list(g);
		g = move_lowest(g);
		// exit(0);
	}
	return (g);
}
