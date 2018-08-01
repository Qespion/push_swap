/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 12:53:31 by oespion           #+#    #+#             */
/*   Updated: 2018/08/01 01:38:43 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		check_list(t_list *start)
{
	t_list	*lst;
	t_list	*tmp;

	if (start == NULL)
		return (1);
	lst = find_lowest(start);
	tmp = lst;
	while (lst->next != find_lowest(start))
	{
		if (lst->next->nb < lst->nb)
		{
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

t_list	**sorting_a(t_list **g, t_list *start_a)
{
	if (g[0]->nb > g[0]->prev->nb && g[0]->next->nb < g[0]->nb
		&& g[0]->prev->nb <= g[0]->next->nb)
	{
		ft_printf("sa\n");
		g = swap_a(g);
	}
	else if ((g[0]->nb >= g[0]->prev->nb || g[0] == start_a)
		&& !check_list(start_a))
	{
		ft_printf("ra\n");
		g = rotate_a(g);
	}
	else if (g[0]->nb < g[0]->prev->nb && g[0] != start_a
		&& (!check_list(start_a) && !check_list(find_lowest(g[0]))))
	{
		ft_printf("pb\n");
		g = push_b(g);
	}
	if (!check_list(start_a))
		return (sorting_a(g, start_a));
	return (g);
}

int		partition_left(t_list *lst, int partition)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != lst)
	{
		if (tmp->p == partition)
			return (1);
		tmp = tmp->next;
	}
	if (tmp->p == partition)
		return (1);
	return (0);
}
