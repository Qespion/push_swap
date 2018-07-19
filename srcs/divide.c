/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:55:01 by oespion           #+#    #+#             */
/*   Updated: 2018/07/19 17:12:09 by oespion          ###   ########.fr       */
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

t_list	**p_divide(t_list **g, int lowest, int biggest, t_list *tmp)
{
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
	if (ft_len_list(g[0]) > 50)
	{
		g = divide(g);
	}
	return (g);
}

t_list	**divide(t_list **g)
{
	int		lowest;
	int		biggest;
	t_list	*tmp;

	tmp = g[0];
	lowest = tmp->p;
	biggest = tmp->p;
	while (tmp->next != g[0])
	{
		biggest = tmp->p > biggest ? tmp->p : biggest;
		lowest = tmp->p < lowest ? tmp->p : lowest;
		tmp = tmp->next;
	}
	tmp = g[0];
	return (p_divide(g, lowest, biggest, tmp));
}
