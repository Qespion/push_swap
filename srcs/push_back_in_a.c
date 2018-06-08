/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:00 by oespion           #+#    #+#             */
/*   Updated: 2018/06/08 11:21:21 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**push_back_in_a(t_list **g)
{
	t_list	*start_a;
	t_list	*current_a;
	int		count1;
	int		count2;

	current_a = g[0];
	start_a = g[0];
	while (g[1] != NULL)
	{
		count1 = 0;
		count2 = 0;
		if (g[1]->nb <= g[0]->nb && (g[0] == start_a || g[1]->nb >= g[0]->prev->nb))
		{
			ft_printf("pa\n");
			g = push_a(g);
		}
		else
		{
			ft_printf("ra\n");
			g = rotate_a(g);
		}
	}
	return (g);
}
