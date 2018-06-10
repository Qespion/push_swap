/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:16:19 by oespion           #+#    #+#             */
/*   Updated: 2018/06/10 15:30:04 by oespion          ###   ########.fr       */
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
	while (r <= len / 2)
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
**	ONLY USE	-swap a		-rotate a
*/

t_list	**swap_basic(t_list **global)
{
	t_list	*debut_a;
	int		tri;

	tri = 1;
	debut_a = global[0];
	while (tri == 1)
	{
		tri = 0;
		while (global[0]->next != debut_a)
		{
			if (global[0]->next->nb < global[0]->nb)
			{
				tri = 1;
				ft_printf("sa\n");
				global = swap_a(global);
			}
			ft_printf("ra\n");
			global = rotate_a(global);
		}
		ft_printf("ra\n");
		global = rotate_a(global);
	}
	return (global);
}

void	solver(t_list *a)
{
	int		r;
	t_list	**global;
	t_list	*b;

	r = 0;
	if (!(global = (t_list**)malloc(sizeof(t_list*) * 2)))
		return ;
	global[0] = a;
	global[1] = NULL;
	global = push_in_b(global);
	global = push_back_in_a(global);
	global = rotate_to_lower(global);
	//print_a(global[0]);
	print_list(global);
	ft_lstdel(global[0]);
	free(global);
}
