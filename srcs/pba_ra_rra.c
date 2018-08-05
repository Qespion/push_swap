/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pba_ra_rra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 04:18:27 by oespion           #+#    #+#             */
/*   Updated: 2018/08/04 14:35:36 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	*find_lowest_elem(t_list **g)
{
	t_list	*elem;
	t_list	*tmp;

	tmp = g[1]->next;
	elem = g[1];
	while (tmp != g[1])
	{
		if (tmp->p < elem->p)
			elem = tmp;
		tmp = tmp->next;
	}
	return (elem);
}

int		ra_for_g1(t_list **g, t_list *elem)
{
	int		len;
	int		list_len;
	t_list	*tmp;

	tmp = g[1];
	len = 0;
	list_len = ft_len_list(g[1]);
	while (tmp != elem)
	{
		tmp = tmp->next;
		len++;
	}
	return (list_len / 2 > len ? 1 : 0);
}

t_list	**ra_rb(t_list **g, t_list *elem)
{
	while (g[1] != elem && (elem->nb > g[0]->nb || elem->nb < g[0]->prev->nb))
	{
		if ((elem->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
		|| (elem->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
			break ;
		ft_printf("rr\n");
		g = rotate_rr(g);
	}
	while (g[1] != elem)
	{
		ft_printf("rb\n");
		g = rotate_b(g);
	}
	while (elem->nb > g[0]->nb || elem->nb < g[0]->prev->nb)
	{
		if ((elem->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
		|| (elem->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
			break ;
		ft_printf("ra\n");
		g = rotate_a(g);
	}
	return (g);
}

t_list	**rra_rb(t_list **g, t_list *elem)
{
	while (g[1] != elem)
	{
		ft_printf("rb\n");
		g = rotate_b(g);
	}
	while (elem->nb > g[0]->nb || elem->nb < g[0]->prev->nb)
	{
		if ((elem->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
		|| (elem->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
			break ;
		ft_printf("rra\n");
		g = reverse_rotate_a(g);
	}
	return (g);
}

t_list	**rra_rrb(t_list **g, t_list *elem)
{
	while (g[1] != elem && (elem->nb > g[0]->nb || elem->nb < g[0]->prev->nb))
	{
		if ((elem->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
		|| (elem->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
			break ;
		ft_printf("rrr\n");
		g = reverse_rotate_rr(g);
	}
	while (g[1] != elem)
	{
		ft_printf("rrb\n");
		g = reverse_rotate_b(g);
	}
	while (elem->nb > g[0]->nb || elem->nb < g[0]->prev->nb)
	{
		if ((elem->nb > find_biggest(g[0])->nb && g[0] == find_biggest(g[0]))
		|| (elem->nb < find_lowest(g[0])->nb && g[0] == find_lowest(g[0])))
			break ;
		ft_printf("rra\n");
		g = reverse_rotate_a(g);
	}
	return (g);
}
