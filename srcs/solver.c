/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:16:19 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 19:27:17 by oespion          ###   ########.fr       */
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
		//ft_printf("nb1 == %d\n", global[1]->nb);
		r++;
	}
//	ft_printf("next of nb = %d\n", global[1]->next->nb);
	return (global);
}

t_list	**roll_base(t_list **gb)
{
	if (gb[0]->nb > gb[0]->next->nb && gb[1]->nb < gb[1]->next->nb)
	{
		gb = swap_ss(gb);
		ft_printf("ss\n");
	}
	else if (gb[0]->nb > gb[0]->next->nb)
	{
		gb = swap_a(gb);
		ft_printf("sa\n");
	}
	else if (gb[1]->nb < gb[1]->next->nb)
	{
		gb = rotate_b(gb);
		ft_printf("sb\n");
	}
	return (gb);
}

void	solver(t_list *a)
{
	t_list	**global;
	t_list	*b;
	int		r;

	r = 0;
	if (!(global = (t_list**)malloc(sizeof(t_list*) * 2)))
		return ;
	global[0] = a;
	global[1] = NULL;
	global = fill_h_in_b(global);
	global = roll_base(global);
	ft_printf("check both %d\n", check_both_list(global));
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
	//ft_printf("after nb1 == %d\n", global[0]->nb);
}
