/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_av.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:37:45 by oespion           #+#    #+#             */
/*   Updated: 2018/06/15 11:52:04 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		calc_ra(t_list **g, t_list *biggest)
{
	int		nb;
	t_list	*b;
	t_list	*a;

	nb = 0;
	b = g[1];
	a = g[0];
	if (g[0] == NULL || g[1] == NULL)
		return (0);
	while (!((b->nb <= a->nb && b->nb >= a->prev->nb)
		|| (a->prev == biggest && b->nb >= biggest->nb)))
	{
		nb++;
		a = a->next;
	}
	return (nb);
}

int		calc_rra(t_list **g, t_list *biggest)
{
	int		nb;
	t_list	*b;
	t_list	*a;

	nb = 0;
	b = g[1];
	a = g[0];
	if (g[0] == NULL || g[1] == NULL)
		return (0);
	while (!((b->nb <= a->nb && b->nb >= a->prev->nb)
		|| (a->prev == biggest && b->nb >= biggest->nb)))
	{
		nb++;
		a = a->prev;
	}
	return (nb);
}

int		calc_other_rb(t_list **g, int nb_max, t_list *biggest, int rotation_of_b)
{
	t_list	*a;
	t_list	*b;
	int		ra;
	int		rra;

	a = g[0];
	b = g[1];
	ra = calc_ra(g, biggest);
	rra = calc_rra(g, biggest);
	if (rra < ra)
		return (rra);
	else
		return (ra);
	return (0);
}

t_list	**do_op(t_list **g, int rotate_b, int rotate_a)
{
	while (rotate_b < 0 && rotate_a < 0)
	{
		ft_printf("rrr\n");
		rotate_b++;
		rotate_a++;
		g = reverse_rotate_rr(g);
	}
	while (rotate_b > 0 && rotate_a > 0)
	{
		ft_printf("rr\n");
		rotate_b--;
		rotate_a--;
		g = reverse_rotate_rr(g);
	}
	while (rotate_b < 0)
	{
		ft_printf("rrb\n");
		rotate_b++;
		g = reverse_rotate_b(g);
	}
	while (rotate_a < 0)
	{
		ft_printf("rra\n");
		rotate_a++;
		g = reverse_rotate_a(g);
	}
	return (g);
}
