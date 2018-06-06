/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:16:19 by oespion           #+#    #+#             */
/*   Updated: 2018/06/06 15:44:12 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**fill_h_in_b(t_list **global)
{
	int	*address;
	int	len;
	int	r;

	r = 0;
	len = 0;
	address = &global[0]->nb;
	global[0] = global[0]->next;
	len++;
	while (&global[0]->nb != address)
	{
		global[0] = global[0]->next;
		len++;
	}
	while (r < len / 2)
	{
		global = push_b(global);
		ft_printf("pb\n");
		r++;
	}
	return (global);
}

t_list	**swap_both(t_list **gb, t_list *start_a, t_list *start_b)
{
	if (gb[0]->nb > gb[0]->next->nb && gb[1]->nb > gb[1]->next->nb
		&& gb[0]->next != start_a && gb[1]->next != start_b)
	{
		gb = swap_ss(gb);
		ft_printf("ss\n");
	}
	else if (gb[0]->nb > gb[0]->next->nb && gb[0]->next != start_a)
	{
		gb = swap_a(gb);
		ft_printf("sa\n");
	}
	else if (gb[1]->nb > gb[1]->next->nb && gb[1]->next != start_b)
	{
		gb = swap_b(gb);
		ft_printf("sb\n");
	}
	return (gb);
}

/*
** --Swap basic to test the functions
**	ONLY USE	-swap a		-rotate a	-reverse rotate a
*/

void	swap_teube(t_list **global, t_list *start_a)
{
	int		r;

	r = 0;

	ft_printf("CHECK = %d\n", check_both_list(global));
/*	while (check_both_list(global))
	{
		if (global[0]->nb > global[0]->next->nb && global[0]->next != start_a)
		{
			global = swap_a(global);
			ft_printf("sa\n");
		}
		else
			global[0] = global[0]->next;
		while (r < 7)
		{
			ft_printf("nb[0] = %d\n", global[0]->nb);
			global[0] = global[0]->next;
			r++;
		}
		ft_printf("\n---\n");
		while (r > 0)
		{
			ft_printf("nb[1] = %d\n", global[1]->nb);
			global[1] = global[1]->next;
			r--;
		}
	}*/
}

void	solver(t_list *a)
{
	int		r;
	t_list	**global;
	t_list	*b;
	t_list	*start_a;
	t_list	*start_b;

	r = 0;
	if (!(global = (t_list**)malloc(sizeof(t_list*) * 2)))
		return ;
	global[0] = a;
	global[1] = NULL;
	global = fill_h_in_b(global);
	start_a = global[0];
	start_b = global[1];
	swap_teube(global, start_a);
	/*while (r < 7)
	{
		ft_printf("nb[0] = %d\n", global[0]->nb);
		global[0] = global[0]->next;
		r++;
	}
	ft_printf("\n---\n");
	while (r > 0)
	{
		ft_printf("nb[1] = %d\n", global[1]->nb);
		global[1] = global[1]->next;
		r--;
	}*/
	ft_printf("after nb1 == %d\n", global[0]->nb);
}
