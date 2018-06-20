/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:42:57 by oespion           #+#    #+#             */
/*   Updated: 2018/06/20 17:02:37 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		middle(t_list *lst, int attribut)
{
	long long 	total;
	int			len;
	t_list		*start;
	t_list		*tmp;

	len = 0;
	total = 0;
	start = lst;
	tmp = lst;
	while (tmp->p == attribut && tmp->next != lst)
	{
		total += tmp->nb;
		tmp = tmp->next;
		len++;
	}
	if (start->next == lst)
	{
		total += tmp->nb;
		len++;
	}
	if (len == 0)
		return(0);
	return (total / len);
}

int		real_median(t_list *lst, int attribut)
{
	int		mid;
	int		lower;
	int		upper;
	t_list	*start;
	t_list	*tmp;

	start = lst;
	if (!lst)
		return (0);
	while (start->p == attribut && start->next != lst)
		start = start->next;
	while (start->p != attribut && start->next != lst)
		start = start->next;
	if (start->p != attribut && start->next->p == attribut)
		start = start->next;
	lower = 1258;
	upper = 54;
	mid = middle(start, attribut);
	while (ft_abs(upper - lower) > 1)
	{
		tmp = start;
		upper = 0;
		lower = 0;
		while (tmp->p == attribut && tmp->next != start)
		{
			tmp->nb >= mid ? upper++ : lower++;
			tmp = tmp->next;
		}
		mid += upper > lower ? 1 : -1;
	}
	return (mid);
}

t_list	*find_lowest(t_list *lst)
{
	t_list	*adr;
	t_list	*start;
	int		nb;

	if (!lst)
		return (NULL);
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
	if (start->nb < nb)
	{
		nb = start->nb;
		adr = start;
	}
	return (adr);
}

t_list	*find_biggest(t_list *lst)
{
	t_list	*adr;
	t_list	*start;
	int		nb;

	if (!lst)
		return (NULL);
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

t_list	**allfunctions(t_list **g, int r)
{
	r == 0 ? ft_printf("sa\n") : 0;
	g = r == 0 ? swap_a(g) : g;
	r == 1 ? ft_printf("sb\n") : 0;
	g = r == 1 ? swap_b(g) : g;
	r == 2 ? ft_printf("ss\n") : 0;
	g = r == 2 ? swap_ss(g) : g;
	r == 3 ? ft_printf("pa\n") : 0;
	g = r == 3 ? push_a(g) : g;
	r == 4 ? ft_printf("pb\n") : 0;
	g = r == 4 ? push_b(g) : g;
	r == 5 ? ft_printf("ra\n") : 0;
	g = r == 5 ? rotate_a(g) : g;
	r == 6 ? ft_printf("rb\n") : 0;
	g = r == 6 ? rotate_b(g) : g;
	r == 7 ? ft_printf("rr\n") : 0;
	g = r == 7 ? rotate_rr(g) : g;
	r == 8 ? ft_printf("rra\n") : 0;
	g = r == 8 ? reverse_rotate_a(g) : g;
	r == 9 ? ft_printf("rrb\n") : 0;
	g = r == 9 ? reverse_rotate_b(g) : g;
	r == 10 ? ft_printf("rrr\n") : 0;
	g = r == 10 ? reverse_rotate_rr(g) : g;
	return (g);
}

int		is_sort(t_list *lowest)
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

int		ra_or_rra(t_list **g, t_list *start_a)
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