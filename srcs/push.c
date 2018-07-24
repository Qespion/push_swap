/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:46:15 by oespion           #+#    #+#             */
/*   Updated: 2018/07/24 14:18:14 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

void	quit_err(t_list **global)
{
	ft_lstdel(global[1]);
	ft_lstdel(global[0]);
	free(global);
	exit(-1);
}

t_list	**end_push_a(t_list **global, int nb, int p)
{
	if (global[0] != NULL)
		global = ft_insert_one(global, 0, nb);
	else
		global[0] = ft_lstnew(nb);
	if (!global[0])
		quit_err(global);
	global[0]->p = p;
	return (global);
}

t_list	**push_a(t_list **global)
{
	int		nb;
	int		p;
	t_list	*tmp;

	if (global[1] == NULL)
		return (global);
	p = global[1]->p;
	nb = global[1]->nb;
	tmp = global[1]->next;
	if (global[1]->next == global[1])
	{
		free(global[1]);
		global[1] = NULL;
	}
	else
	{
		ft_lstdelone(global[1]);
		global[1] = tmp;
	}
	return (end_push_a(global, nb, p));
}

t_list	**end_push_b(t_list **global, int nb, int p)
{
	if (global[1] != NULL)
		global = ft_insert_one(global, 1, nb);
	else
		global[1] = ft_lstnew(nb);
	if (!global[1])
		quit_err(global);
	global[1]->p = p;
	return (global);
}

t_list	**push_b(t_list **global)
{
	int		nb;
	int		p;
	t_list	*tmp;
	t_list	*todel;

	if (global[0] == NULL)
		return (global);
	p = global[0]->p;
	todel = global[0];
	nb = global[0]->nb;
	tmp = global[0]->next;
	if (global[0]->next == global[0])
	{
		free(global[0]);
		global[0] = NULL;
	}
	else
	{
		ft_lstdelone(global[0]);
		global[0] = tmp;
	}
	return (end_push_b(global, nb, p));
}
