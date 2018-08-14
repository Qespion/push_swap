/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:21:13 by oespion           #+#    #+#             */
/*   Updated: 2018/08/14 10:03:30 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**rotate_a(t_list **global)
{
	if (global[0] == NULL)
		return (global);
	global[0] = global[0]->next;
	return (global);
}

t_list	**rotate_b(t_list **global)
{
	if (global[1] == NULL)
		return (global);
	global[1] = global[1]->next;
	return (global);
}

t_list	**rotate_rr(t_list **global)
{
	if (global[1] == NULL || global[0] == NULL)
		return (global);
	global = rotate_a(global);
	global = rotate_b(global);
	return (global);
}
