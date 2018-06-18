/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:06:41 by oespion           #+#    #+#             */
/*   Updated: 2018/06/18 17:56:24 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		number_in_the_middle(t_list *g)
{
	long long	total;
	t_list		*start_list;
	t_list		*tmp;
	int			nb_w;

	total = 0;
	nb_w = 0;
	tmp = g;
	start_list = g;
	while (tmp->next != start_list)
	{
		total += tmp->nb;
		tmp = tmp->next;
		nb_w++;
	}
	total += tmp->nb;
	nb_w++;
	return (total / nb_w);
}

t_list	**push_half_in_a(t_list **g)
{
	int	mediane;
	t_list	*start;

	if (ft_len_list(g[1]) < 15)
		return (g);
	mediane = number_in_the_middle(g[1]);
	start = g[1];
	while (g[1]->next != start)
	{
		if (g[1]->nb > mediane)
		{
			if (g[1] == start)
				start = g[1]->next;
			g = push_a(g);
			g[0]->p = 1;
			ft_printf("pa\n");
		}
		else
		{
			g = rotate_b(g);
			ft_printf("rb\n");
		}
	}
	if (g[1]->nb < mediane)
	{
		g = push_a(g);
		g[0]->p = 1;
		ft_printf("pa\n");
	}
	return (g);
}

int		is_part_a_sort(t_list *g)
{
	t_list	*debut;
	t_list	*start;

	start = g->prev;
	debut = g;
	while (debut->p == 0 && debut != start)
		debut = debut->prev;
	while (debut->p == 1)
		debut = debut->prev;
	debut = debut->next;
	while (debut->nb <= debut->next->nb)
		debut = debut->next;
	if (debut->next->p == 1)
		return (0);
	return (1);
}

t_list	**tri_both(t_list **g)
{
	t_list *lowest_b;

	lowest_b = find_lowest(g[1]);
	if (g[0]->nb > g[0]->next->nb && g[0]->p == 1 && g[0]->next->p == 1)
	{
		if (g[1]->nb > g[1]->next->nb && g[1]->next != lowest_b)
		{
			ft_printf("ss\n");
			g = swap_ss(g);
		}
		else
		{
			ft_printf("sa\n");
			g = swap_a(g);
		}
		while (g[0]->prev->nb > g[0]->nb && g[0]->prev->p == 1)
		{
			if (g[1]->prev->nb > g[1]->nb && g[1] != lowest_b)
			{
				while (g[1]->prev->nb > g[1]->nb && g[1] != lowest_b && g[0]->prev->nb > g[0]->nb && g[0]->prev->p == 1)
				{
					ft_printf("rrr\n");
					g = reverse_rotate_rr(g);
				}
			}
			else
			{
				ft_printf("rra\n");
				g = reverse_rotate_a(g);
			}
			if (g[1]->prev->nb > g[1]->nb && g[1] != lowest_b && g[0]->prev->nb > g[0]->nb && g[0]->prev->p == 1)
			{
				ft_printf("ss\n");
				g = swap_ss(g);
			}
			else
			{
				ft_printf("sa\n");
				g = swap_a(g);
			}
		}
	}
	if (!is_part_a_sort(g[0]))
	{
		if (!is_sort(g[1]))
		{
			ft_printf("rr\n");
			g = rotate_rr(g);
		}
		else
		{
			ft_printf("ra\n");
			g = rotate_a(g);
		}
	}
	if (!is_part_a_sort(g[0]))
		return (tri_both(g));
	return (g);
}

int		better_in_rev(t_list **g)
{
	int		reverse;
	int		rotate;
	t_list	*tmp;

	reverse = 0;
	rotate = 0;
	tmp = g[0];
	while (tmp->next->p == 0)
	{
		tmp = tmp->next;
		rotate++;
	}
	tmp = g[0];
	while (tmp->p == 1)
	{
		tmp = tmp->prev;
		reverse++;
	}
	if (reverse < rotate)
		return (1);
	return (0);
}

int		find_p_in_a(t_list *g)
{
	t_list	*start;
	int		p;

	p = 0;
	start = g;
	while (start->next != g)
	{
		if (start->p)
			p++;
		start = start->next;
	}
	if (start->p)
		p++;
	if (p == 0)
		return (0);
	return (1);
}

t_list	**remove_p_in_a(t_list **g)
{
	t_list	*lowest_b;

	if (find_p_in_a(g[0]) == 0)
		return (g);
	lowest_b = find_lowest(g[1]);
	if (!better_in_rev(g))
	{
		while (g[0]->next == 0)
		{
			while (g[0]->next == 0)
			g = rotate_a(g);
			ft_printf("ra\n");
		}
		g = rotate_a(g);
		ft_printf("ra\n");
	}
	else
	{
		while (g[0]->prev->p == 1)
		{
			g = reverse_rotate_a(g);
			ft_printf("rra\n");
		}
	}
	while (g[0]->p == 1)
	{
		g = push_b(g);
		ft_printf("pb\n");
	}
	return (g);
}

t_list	**tri_b(t_list **g)
{
	int		count_in_a;
	t_list	*start_b;
	t_list	*start_a;
	t_list	*biggest;

	count_in_a = 0;
	start_b = find_lowest(g[0]);
	biggest = find_biggest(g[1]);
	if (!g[1])
		return (g);
	g = push_half_in_a(g);
	// ft_printf("-----------------\n");
	// print_list(g);
	// ft_printf("-----------------\n");
	g = tri_both(g);
	g = remove_p_in_a(g);
	// print_list(g);
	return (g);
}
