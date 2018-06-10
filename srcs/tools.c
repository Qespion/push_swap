/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:42:57 by oespion           #+#    #+#             */
/*   Updated: 2018/06/10 13:20:26 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	*find_lowest(t_list *lst)
{
	t_list	*adr;
	t_list	*start;
	int		nb;

	adr = lst;
	nb = lst->nb;
	start = lst;
	while (start->next != lst)
	{
		if (start->nb < nb)
		{
			nb = start->nb;
			adr = start;
		}
		start = start->next;
	}
	return (adr);
}

t_list	*find_biggest(t_list *lst)
{
	t_list	*adr;
	t_list	*start;
	int		nb;

	adr = lst;
	nb = lst->nb;
	start = lst;
	while (lst->next != start)
	{
		if (lst->nb >= nb)
		{
			nb = lst->nb;
			adr = lst;
		}
		lst = lst->next;
	}
	if (lst->nb >= nb)
	{
		nb = lst->nb;
		adr = lst;
	}
	return (adr);
}

t_list	**move_to_lower(t_list **lst, int r)
{
	t_list	*start;

	start = find_lowest(lst[0]);
	if (r == 1)
	{
		while (lst[0] != start)
		{
			lst = rotate_a(lst);
			ft_printf("ra\n");
		}
	}
	else
		while (lst[0] != start)
		{
			lst = reverse_rotate_a(lst);
			ft_printf("rra\n");
		}
	return (lst);
}

t_list	**rotate_to_lower(t_list **lst)
{
	t_list	*lowest;
	t_list	*find;
	int		ra;
	int		rra;

	lowest = find_lowest(lst[0]);
	ra = 0;
	rra = 0;
	find = lst[0];
	while (find != lowest)
	{
		find = find->next;
		ra++;
	}
	find = lst[0];
	while (find != lowest)
	{
		find = find->prev;
		rra++;
	}
	lst = ra >= rra ? move_to_lower(lst, 0) : move_to_lower(lst, 1);
	return (lst);
}
