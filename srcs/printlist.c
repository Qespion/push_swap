/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:16:16 by oespion           #+#    #+#             */
/*   Updated: 2018/07/26 17:30:43 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

/*
**	debug file
** 	print both list
*/

void	print_list(t_list **global)
{
	t_list	*start_a;
	t_list	*start_b;

	start_a = global[0];
	start_b = global[1];
	ft_printf("----\n");
	if (global[0])
	{
		ft_printf("list a = %d, %d\n", global[0]->nb, global[0]->p);
		global[0] = global[0]->next;
		while(global[0] != start_a)
		{
			ft_printf("list a = %d, %d\n", global[0]->nb, global[0]->p);
			global[0] = global[0]->next;
		}
	}
	ft_printf("\n----\n\n");
	if (global[1])
	{
		ft_printf("list b = %d, %d\n", global[1]->nb, global[1]->p);
		global[1] = global[1]->next;
		while (global[1] != start_b)
		{
			ft_printf("list b = %d, %d\n", global[1]->nb, global[1]->p);
			global[1] = global[1]->next;
		}
	}
	ft_printf("----\n");
}

void	print_a(t_list *a)
{
	t_list	*start;

	start = a;
	while (start->next != a)
	{
		ft_printf("nb -> %d\n", start->nb);
		start = start->next;
	}
	ft_printf("nb -> %d\n", start->nb);
}
