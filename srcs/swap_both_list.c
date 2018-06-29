/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:30:44 by oespion           #+#    #+#             */
/*   Updated: 2018/06/29 18:08:33 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**sort_a(t_list **g)
{
	t_list	*start_a;

	start_a = find_lowest(g[0]);
	while ((g[0]->prev->nb <= g[0]->nb || g[0] == start_a) && g[0]->nb <= g[0]->next->nb)
	if (g[0]->next != g[0])
	{
		ft_printf("pb\n");
		g = push_b(g);
	}
	print_list(g);
	return (g);
}

t_list	**swap_both_list(t_list **g)
{
	// g = subdivide(g);
	g = sort_a(g);
	return (g);
}