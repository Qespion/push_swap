/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:00 by oespion           #+#    #+#             */
/*   Updated: 2018/06/08 16:24:34 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**push_back_in_a(t_list **g)
{
	t_list	*start_a;
	t_list	*current_a;
	t_list	*biggest;

	current_a = g[0];
	start_a = find_lowest(g[0]);
	while (g[1] != NULL)
	{
		biggest = find_biggest(g[0]);
		if (g[1]->nb <= g[0]->nb && g[1]->nb >= g[0]->prev->nb)
		{
			push_a(g);
			ft_printf("pa\n");
		}
		else if (g[0]->prev == biggest && g[1]->nb >= biggest->nb)
		{
			push_a(g);
			ft_printf("pa\n");
		}
		else
		{
			rotate_a(g);
			ft_printf("ra\n");
		}
	}
	return (g);
}
