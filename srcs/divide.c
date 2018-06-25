/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:55:01 by oespion           #+#    #+#             */
/*   Updated: 2018/06/25 17:17:31 by oespion          ###   ########.fr       */
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
	int		median;
	int		deep;

	deep = 1;
	median = real_median(g[0], deep);
	while (!upper_left(g[1], median, deep))
	{
		if (g[1]->nb >= median)
		{
			g = push_a(g);
			g[0]->p += 1;
			printf("pa\n");
		}
		else
		{
			g = rotate_b(g);
			printf("ra\n");
		}
	}
	print_list(g);
	// conquer(t_list **g);
	return (g);
}
