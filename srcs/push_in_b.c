/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:26:17 by oespion           #+#    #+#             */
/*   Updated: 2018/07/19 12:56:39 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		lower_partition_left(t_list *lst, int partition)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != lst)
	{
		if (tmp->p < partition)
			return (1);
		tmp = tmp->next;
	}
	if (tmp->p < partition)
		return (1);
	return (0);
}

int		partition_nb(t_list **g)
{
	int		nb;
	t_list	*tmp;

	tmp = g[0];
	nb = g[0]->p;
	while (tmp->next != g[0])
	{
		nb = nb < tmp->p ? tmp->p : nb;
		tmp = tmp->next;
	}
	nb = nb < tmp->p ? tmp->p : nb;
	return (nb);
}

int		lower_partition(t_list *lst)
{
	int		lowest;
	t_list	*tmp;

	lowest = lst->p;
	tmp = lst;
	while (tmp->next != lst)
	{
		lowest = tmp->p < lowest ? tmp->p : lowest;
		tmp = tmp->next;
	}
	lowest = tmp->p < lowest ? tmp->p : lowest;
	return (lowest);
}

t_list	**lower_than_limit2(t_list **g, int limit2)
{
	ft_printf("pb\n");
	g = push_b(g);
	if (g[0]->next != g[0])
	{
		ft_printf("rb\n");
		g = rotate_b(g);
	}
	return (g);
}

t_list	**push_in_b(t_list **g)
{
	int	limit1;
	int	limit2;
	int	nb_partition;

	nb_partition = calc_nb_partition(g, ft_len_list(g[0]));
	limit1 = nb_partition / 3;
	limit2 = nb_partition / 3 * 2;
	while (lower_partition_left(g[0], limit2))
	{
		if (g[0]->p <= limit1)
		{
			ft_printf("pb\n");
			g = push_b(g);
		}
		else if (g[0]->p <= limit2)
			g = lower_than_limit2(g, limit2);
		else
		{
			ft_printf("ra\n");
			g = rotate_a(g);
		}
	}
	return (g);
}
