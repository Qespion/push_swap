/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:16:19 by oespion           #+#    #+#             */
/*   Updated: 2018/08/14 09:40:37 by oespion          ###   ########.fr       */
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

t_list	**swap_bogo(t_list **global)
{
	int		r;
	t_list	*lowest;

	srand(time(NULL));
	r = rand() % 10;
	lowest = find_lowest(global[0]);
	while (!is_sort(lowest) || global[1] != NULL)
	{
		global = allfunctions(global, r);
		lowest = find_lowest(global[0]);
		r = rand() % 10;
	}
	return (global);
}

void	end_solver(t_list **global)
{
	global = rotate_to_lower(global);
	free(global);
}

void	solver(t_list *a, int bogo)
{
	t_list	**global;
	t_list	*b;

	if (!(global = (t_list**)malloc(sizeof(t_list*) * 2)))
		return ;
	global[0] = a;
	global[1] = NULL;
	if (bogo == 0)
	{
		if (ft_lst_len(global[0]) > 30)
		{
			while (ft_len_list(global[0]) > 28)
			{
				global = partition_list(global);
				global = push_in_b(global);
			}
			global = swap_both_list(global);
		}
		else
			global = sorting_a(global, find_lowest(global[0]));
		global = push_back_in_a(global);
	}
	else
		global = swap_bogo(global);
	end_solver(global);
}
