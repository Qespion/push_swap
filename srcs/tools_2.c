/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 13:46:16 by oespion           #+#    #+#             */
/*   Updated: 2018/07/19 13:47:17 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int	is_sort(t_list *lowest)
{
	t_list	*curr;

	if (!lowest)
		return (0);
	curr = lowest;
	while (curr->next != lowest)
	{
		if (curr->nb > curr->next->nb)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	ra_or_rra(t_list **g, t_list *start_a)
{
	t_list	*cpy_0;
	int		rra;
	int		ra;

	rra = 0;
	ra = 0;
	cpy_0 = g[0];
	if (check_list(start_a))
		return (1);
	while (!((cpy_0->nb > cpy_0->next->nb && cpy_0->next->nb >= cpy_0->prev->nb
		&& cpy_0->nb <= cpy_0->next->next->nb) || (cpy_0->next->nb < cpy_0->nb
		&& cpy_0->next != start_a)))
	{
		cpy_0 = cpy_0->next;
		ra++;
	}
	cpy_0 = g[0];
	while (!((cpy_0->nb > cpy_0->next->nb && cpy_0->next->nb >= cpy_0->prev->nb
		&& cpy_0->nb <= cpy_0->next->next->nb) || (cpy_0->next->nb < cpy_0->nb
		&& cpy_0->next != start_a)))
	{
		cpy_0 = cpy_0->prev;
		rra++;
	}
	return (rra < ra ? 0 : 1);
}

int	ft_lst_len(t_list *lst)
{
	int		total;
	t_list	*tmp;

	total = 1;
	tmp = lst;
	while (tmp->next != lst)
	{
		total++;
		tmp = tmp->next;
	}
	return (total);
}
