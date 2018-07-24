/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:00 by oespion           #+#    #+#             */
/*   Updated: 2018/07/24 13:59:51 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		better_in_rra_ra(t_list **g)
{
	int	ra;
	int rra;
	t_list	*tmp;

	tmp = g[0];
	ra = 0;
	rra = 0;
	while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
	{
		if ((g[1]->nb > find_biggest(g[0])->nb && tmp->prev == find_biggest(g[0]))
			|| g[1]->nb < find_lowest(g[0])->nb && tmp == find_lowest(g[0]))
			break;
		ra++;
		tmp = tmp->next;
	}
	tmp = g[0];
	while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
	{
		if ((g[1]->nb > find_biggest(g[0])->nb && tmp->prev == find_biggest(g[0]))
			|| g[1]->nb < find_lowest(g[0])->nb && tmp == find_lowest(g[0]))
			break;
		rra++;
		tmp = tmp->prev;
	}
	return (ra <= rra ? 1 : 0);
}

int		better_in_rb_rrb(t_list **g, int r)
{
	return (ft_len_list(g[1]) / 2 < r ? 0 : 1);
}

t_list	**find_move_b(t_list **g, int r)
{
	int		total;
	t_list	*tmp;

	total = 1;
	tmp = g[0];
	if (better_in_rra_ra(g))
	{
		if (better_in_rb_rrb(g, r))
		{
			while (r > 0 && (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb))
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && tmp->prev == find_biggest(g[0]))
						|| g[1]->nb < find_lowest(g[0])->nb && tmp == find_lowest(g[0]))
					break;
				r--;
				tmp = tmp->next;
				total++;
			}
			while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && tmp->prev == find_biggest(g[0]))
						|| g[1]->nb < find_lowest(g[0])->nb && tmp == find_lowest(g[0]))
					break;
				total++;
				tmp = tmp->next;
			}
			if (r > 0)
				total += r;
		}
		else
		{
			while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && tmp->prev == find_biggest(g[0]))
						|| g[1]->nb < find_lowest(g[0])->nb && tmp == find_lowest(g[0]))
					break;
				total++;
				tmp = tmp->next;
			}
			total += r;
		}
	}
	else
	{
		if (better_in_rb_rrb(g, r))
		{
			while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && tmp->prev == find_biggest(g[0]))
						|| g[1]->nb < find_lowest(g[0])->nb && tmp == find_lowest(g[0]))
					break;
				total++;
				tmp = tmp->prev;
			}
			total += r;
		}
		else
		{
			while (r < ft_len_list(g[1]) && (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb))
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && tmp->prev == find_biggest(g[0]))
						|| g[1]->nb < find_lowest(g[0])->nb && tmp == find_lowest(g[0]))
					break;
				r++;
				tmp = tmp->prev;
				total++;
			}
			while (g[1]->nb > tmp->nb || g[1]->nb < tmp->prev->nb)
			{
				if ((g[1]->nb > find_biggest(g[0])->nb && tmp->prev == find_biggest(g[0]))
						|| g[1]->nb < find_lowest(g[0])->nb && tmp == find_lowest(g[0]))
					break;
				total++;
				tmp = tmp->prev;
			}
			total += ft_len_list(g[1]) - r;
		}
	}
	g[1]->p = total;
	return (g);
}

t_list	**get_moves_lst(t_list **g)
{
	t_list	*tmp;
	int		r;

	r = 0;
	tmp = g[1];
	while (g[1]->next != tmp)
	{
		g = find_move_b(g, r);
		r++;
		g[1] = g[1]->next;
	}
	g = find_move_b(g, r);
	g[1] = g[1]->next;
	return (g);
}

t_list	*find_lowest_move(t_list **g)
{
	t_list	*lowest;
	t_list	*tmp;

	tmp = g[1];
	lowest = g[1];
	while (tmp->next != g[1])
	{
		if (lowest->p > g[1]->p)
			lowest = g[1];
		tmp = tmp->next;
	}
	if (lowest->p > g[1]->p)
			lowest = g[1];
	return (lowest);
}

int		find_lowest_move_nb(t_list **g)
{
	int		r;
	t_list	*lowest;
	t_list	*tmp;

	r = 0;
	tmp = g[1];
	lowest = g[1];
	while (tmp->next != g[1])
	{
		if (lowest->p > g[1]->p)
			lowest = g[1];
		tmp = tmp->next;
	}
	if (lowest->p > g[1]->p)
			lowest = g[1];
	tmp = g[1];
	while (tmp != lowest)
	{
		tmp = tmp->next;
		r++;
	}
	return (r);
}

t_list	**move_back(t_list **g)
{
	int		r;
	t_list	*lowest;

	r = find_lowest_move_nb(g);
	lowest = find_lowest_move(g);
	if (better_in_rra_ra(g))
	{
		if (better_in_rb_rrb(g, r))
		{
			while (r > 0 && (lowest->nb > g[0]->nb || lowest->nb < g[0]->prev->nb))
			{
				if ((lowest->nb > find_biggest(g[0])->nb && g[0]->prev == find_biggest(g[0]))
						|| lowest->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0]))
					break;
				r--;
				ft_printf("rr\n");
				g = rotate_rr(g);
			}
			while (lowest->nb > g[0]->nb || lowest->nb < g[0]->prev->nb)
			{
				if ((lowest->nb > find_biggest(g[0])->nb && g[0]->prev == find_biggest(g[0]))
						|| lowest->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0]))
					break;
				ft_printf("ra\n");
				g = rotate_a(g);
			}
			while (g[1] != lowest)
			{
				ft_printf("rb\n");
				g = rotate_b(g);
			}
		}
		else
		{
			while (lowest->nb > g[0]->nb || lowest->nb < g[0]->prev->nb)
			{
				if ((lowest->nb > find_biggest(g[0])->nb && g[0]->prev == find_biggest(g[0]))
						|| lowest->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0]))
					break;
				ft_printf("ra\n");
				g = rotate_a(g);
			}
			while (g[1] != lowest)
			{
				ft_printf("rrb\n");
				g = reverse_rotate_b(g);
			}
		}
	}
	else
	{
		if (better_in_rb_rrb(g, r))
		{
			while (lowest->nb > g[0]->nb || lowest->nb < g[0]->prev->nb)
			{
				if ((lowest->nb > find_biggest(g[0])->nb && g[0]->prev == find_biggest(g[0]))
						|| lowest->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0]))
					break;
				ft_printf("rra\n");
				g = reverse_rotate_a(g);
			}
			while (g[1] != lowest)
			{
				ft_printf("rb\n");
				g = rotate_b(g);
			}
		}
		else
		{
			while (r < ft_len_list(g[1]) && (lowest->nb > g[0]->nb || lowest->nb < g[0]->prev->nb))
			{
				if ((lowest->nb > find_biggest(g[0])->nb && g[0]->prev == find_biggest(g[0]))
						|| lowest->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0]))
					break;
				r++;
				ft_printf("rrr\n");
				g = reverse_rotate_rr(g);
			}
			while (lowest->nb > g[0]->nb || lowest->nb < g[0]->prev->nb)
			{
				if ((lowest->nb > find_biggest(g[0])->nb && g[0]->prev == find_biggest(g[0]))
						|| lowest->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0]))
					break;
				ft_printf("rra\n");
				g = reverse_rotate_a(g);
			}
			while (g[1] != lowest)
			{
				ft_printf("rrb\n");
				g = reverse_rotate_b(g);
			}
		}
	}
	ft_printf("pa\n");
	g = push_a(g);
	return (g);
}

t_list	**push_back_in_a(t_list **g)
{
	while (g[1])
	{
		g = get_moves_lst(g);
		g = move_back(g);
	}
	//print_list(g);
	return (g);
}
