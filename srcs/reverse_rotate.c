/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:25:45 by oespion           #+#    #+#             */
/*   Updated: 2018/08/14 10:03:34 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**reverse_rotate_a(t_list **global)
{
	if (global[0] == NULL)
		return (global);
	global[0] = global[0]->prev;
	return (global);
}

t_list	**reverse_rotate_b(t_list **global)
{
	if (global[1] == NULL)
		return (global);
	global[1] = global[1]->prev;
	return (global);
}

t_list	**reverse_rotate_rr(t_list **global)
{
	if (global[1] == NULL || global[0] == NULL)
		return (global);
	global = reverse_rotate_a(global);
	global = reverse_rotate_b(global);
	return (global);
}
