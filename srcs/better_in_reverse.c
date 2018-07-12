/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_in_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:21:51 by oespion           #+#    #+#             */
/*   Updated: 2018/07/12 14:26:31 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		better_in_reverse_ra(t_list **g, int base_count, t_list *biggest)
{
	t_list	*cpy_0;
	t_list	*cpy_1;
	int		count;

	cpy_0 = g[0];
	cpy_1 = g[1];
	count = 0;
	while (!(cpy_1->nb <= cpy_0->nb && cpy_1->nb >= cpy_0->prev->nb)
		&& !(cpy_0->prev == biggest && cpy_1->nb >= biggest->nb))
	{
		count++;
		cpy_0 = cpy_0->prev;
	}
	if (count >= base_count)
		return (0);
	return (count);
}

int		better_in_reverse_rb(t_list **g, int base_count, t_list *biggest)
{
	t_list	*cpy_0;
	t_list	*cpy_1;
	int		count;
	int		len;

	len = 1;
	cpy_0 = g[0];
	cpy_1 = g[1];
	count = 1;
	while (cpy_1->next != g[1])
	{
		cpy_1 = cpy_1->next;
		len++;
	}
	cpy_1 = cpy_1->next;
	while (!(cpy_1->nb <= cpy_0->nb && cpy_1->nb >= cpy_0->prev->nb)
		&& !(cpy_0->prev == biggest && cpy_1->nb >= biggest->nb))
	{
		count++;
		cpy_1 = cpy_1->prev;
		if (count > len)
			return (0);
	}
	if (count >= base_count)
		return (0);
	return (count);
}

int		better_in_rrr(t_list **g, int base_count, t_list *biggest)
{
	t_list	*cpy_0;
	t_list	*cpy_1;
	int		count;

	count = 0;
	cpy_0 = g[0];
	cpy_1 = g[1];
	return (0);
}
