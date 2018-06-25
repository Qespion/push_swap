/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:32:58 by oespion           #+#    #+#             */
/*   Updated: 2018/06/25 16:05:16 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**swap_a(t_list **global)
{
	int	tmp;
	int	tmp_p;


	if (!global[0])
		return (global);
	tmp = global[0]->nb;
	tmp_p = global[0]->p;
	global[0]->p = global[0]->next->p;
	global[0]->nb = global[0]->next->nb;
	global[0]->next->p = tmp_p;
	global[0]->next->nb = tmp;
	return (global);
}

t_list	**swap_b(t_list **global)
{
	int	tmp;
	int	tmp_p;

	if (!global[1])
		return (global);
	tmp = global[1]->nb;
	tmp_p = global[1]->p;
	global[1]->p = global[1]->next->p;
	global[1]->nb = global[1]->next->nb;
	global[1]->next->p = tmp_p;
	global[1]->next->nb = tmp;
	return (global);
}

t_list	**swap_ss(t_list **global)
{
	global = swap_a(global);
	global = swap_b(global);
	return (global);
}
