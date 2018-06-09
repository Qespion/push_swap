/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:15:53 by oespion           #+#    #+#             */
/*   Updated: 2018/06/09 15:19:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**apply_checker(t_list **g, char *str)
{
	// if (ft_strcmp(str, "rrr"))
	// 	g = reverse_rotate_rr(g);
	// else if (ft_strcmp(str, "rrb"))
	// 	g = reverse_rotate_b(g);
	// else if (ft_strcmp(str, "rra"))
	// 	g = reverse_rotate_a(g);
	// else if (ft_strcmp(str, "ra"))
	// 	g = rotate_a(g);
	// else if (ft_strcmp(str, "rb"))
	// 	g = rotate_b(g);
	// else if (ft_strcmp(str, "rr"))
	// 	g = rotate_rr(g);
	// else if (ft_strcmp(str, "sa"))
	// 	g = swap_a(g);
	// else if (ft_strcmp(str, "sb"))
	// 	g = swap_b(g);
	// else if (ft_strcmp(str, "ss"))
	// 	g = swap_ss(g);
	// else if (ft_strcmp(str, "pa"))
	// 	g = push_a(g);
	// else if (ft_strcmp(str, "pb"))
	// 	g = push_b(g);
	return (g);
}

int		check_order(t_list **g)
{
	t_list	*start;
	int		r;

	r = 0;
	start = g[0];
	while (start->next != g[0])
	{
		;
	}
	return (0);
}