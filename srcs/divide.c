/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:55:01 by oespion           #+#    #+#             */
/*   Updated: 2018/07/01 15:47:35 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		upper_left(t_list *g, int mid_nb, int attribut)
{
	t_list	*tmp;

	tmp = g;
	while (tmp->next != g && tmp->p == attribut)
	{
		if (tmp->nb >= mid_nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	**divide(t_list **g)
{
	int		lowest;
	int		biggest;
	t_list	*tmp;

	tmp = g[0];
	lowest = tmp->p;
	biggest = tmp->p;
	// ft_printf("bggest = %d\n", biggest);
	// ft_printf("lwest = %d\n", lowest);
	if (biggest - lowest < 3)
		return (g);
	while (tmp->next != g[0])
	{
		biggest = tmp->p > biggest ? tmp->p : biggest;
		lowest = tmp->p < lowest ? tmp->p : lowest;
		tmp = tmp->next;
	}
	tmp = g[0];
	while (g[0]->next != tmp)
	{
		if (g[0]->p <= (biggest + lowest) / 2)
		{
			if (g[0] == tmp)
				tmp = g[0]->next;
			ft_printf("pb\n");
			g = push_b(g);
		}
		else
		{
			ft_printf("ra\n");
			g = rotate_a(g);
		}
	}
	return (g);
}

int		partition_left(t_list *lst, int partition)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != lst)
	{
		if (tmp->p == partition)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->p == partition)
		return (0);
	return (1);
}

t_list	**subdivide(t_list **g)
{
	int		lowest;
	int		slowest;
	t_list	*tmp;

	tmp = g[0];
	lowest = tmp->p;
	slowest = tmp->p;
	while (tmp->next != g[0])
	{
		slowest = tmp->p < lowest ? lowest : slowest;
		lowest = tmp->p < lowest ? tmp->p : lowest;
		tmp = tmp->next;
	}
	tmp = g[0];
	while (!partition_left(g[0], lowest))
	{
		if (g[0]->p == lowest || g[0]->p == slowest)
		{
			ft_printf("pb\n");
			g = push_b(g);
				if (g[0]->p == lowest)
				{
					ft_printf("rb\n");
					g = rotate_b(g);
				}
		}
		else
		{
			ft_printf("ra\n");
			g = rotate_a(g);
		}
	}
	return (g);
}

t_list	**empty_a(t_list **g)
{
	t_list	*tmp;

	tmp = g[0];
	while (g[0]->next != g[0])
	{
		ft_printf("pb\n");
		g = push_b(g);
	}
	return (g);
}
