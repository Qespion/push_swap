/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:46:15 by oespion           #+#    #+#             */
/*   Updated: 2018/06/06 15:30:05 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**push_a(t_list **global)
{
	int 	nb;
	t_list	*tmp;

	if (global[1] == NULL)
		return (global);
	nb = global[1]->nb;
	tmp = global[1]->next;
	ft_lstdelone(global[1]);
	global[1] = tmp;
	if (global[0] != NULL)
		global = ft_insert_one(global, 0, nb);
	else
		global[0] = ft_lstnew(nb);
	return (global);
}

t_list	**push_b(t_list **global)
{
	int 	nb;
	t_list	*tmp;
	t_list	*todel;

	if (global[0] == NULL)
		return (global);
	todel = global[0];
	nb = global[0]->nb;
	tmp = global[0]->next;
	ft_lstdelone(global[0]);
	global[0] = tmp;
	if (global[1] != NULL)
		global = ft_insert_one(global, 1, nb);
	else
		global[1] = ft_lstnew(nb);
	return (global);
}
