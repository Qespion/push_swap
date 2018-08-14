/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:46:15 by oespion           #+#    #+#             */
/*   Updated: 2018/08/14 11:06:57 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**push_an(t_list **global, t_list *tmp)
{
	t_list	*prevv;
	t_list	*nextt;

	if (!global[0])
	{
		prevv = tmp;
		nextt = tmp;
	}
	else
	{
		prevv = global[0]->prev;
		nextt = global[0];
	}
	prevv->next = tmp;
	nextt->prev = tmp;
	tmp->next = nextt;
	tmp->prev = prevv;
	global[0] = tmp;
	return (global);
}

t_list	**push_a(t_list **global)
{
	t_list	*tmp;
	t_list	*prevv;
	t_list	*nextt;

	if (global[1] == NULL)
		return (global);
	if (global[1]->next == global[1])
	{
		tmp = global[1];
		global[1] = NULL;
	}
	else
	{
		prevv = global[1]->prev;
		nextt = global[1]->next;
		prevv->next = global[1]->next;
		nextt->prev = global[1]->prev;
		tmp = global[1];
		global[1] = global[1]->next;
	}
	return (push_an(global, tmp));
}

t_list	**push_bn(t_list **global, t_list *tmp)
{
	t_list	*prevv;
	t_list	*nextt;

	if (!global[1])
	{
		prevv = tmp;
		nextt = tmp;
	}
	else
	{
		prevv = global[1]->prev;
		nextt = global[1];
	}
	prevv->next = tmp;
	nextt->prev = tmp;
	tmp->next = nextt;
	tmp->prev = prevv;
	global[1] = tmp;
	return (global);
}

t_list	**push_b(t_list **global)
{
	t_list	*tmp;
	t_list	*prevv;
	t_list	*nextt;

	if (global[0] == NULL)
		return (global);
	if (global[0]->next == global[0])
	{
		tmp = global[0];
		global[0] = NULL;
	}
	else
	{
		prevv = global[0]->prev;
		nextt = global[0]->next;
		prevv->next = global[0]->next;
		nextt->prev = global[0]->prev;
		tmp = global[0];
		global[0] = global[0]->next;
	}
	return (push_bn(global, tmp));
}
