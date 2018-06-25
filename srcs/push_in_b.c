/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:26:17 by oespion           #+#    #+#             */
/*   Updated: 2018/06/25 17:22:53 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		check_list(t_list *start)
{
	t_list	*lst;

	if (start == NULL)
		return (1);
	lst = start;
	while (lst->next != start)
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
	else if ((g[0]->nb >= g[0]->prev->nb || g[0] == start_a) && !check_list(start_a))
	{
		ft_printf("ra\n");
		g = rotate_a(g);
	}
	else if (g[0]->nb < g[0]->prev->nb && g[0] != start_a && (!check_list(start_a) && !check_list(find_lowest(g[0]))))
	{
		g[0]->p += 1;
		ft_printf("pb\n");
		g = push_b(g);
	}
	if (!check_list(start_a) && !check_list(find_lowest(g[0])))
		return (sorting_a(g, start_a));
	return (g);
}

t_list	**push_in_b(t_list **g)
{
	t_poz	*best_start;
	t_list	*tmp;

	tmp = g[0];
	if (!(best_start = (t_poz*)malloc(sizeof(t_poz))))
		return (NULL);
	best_start->starting = g[0];
	best_start->len = 0;
	best_start = best_starting_pos(best_start, tmp);
	while (tmp->next != g[0])
	{
		// ft_printf("start nb = %d\n", best_start->starting->nb);
		// ft_printf("best_start len = %d\n", best_start->len);
		tmp = tmp->next;
		// best_start = best_starting_pos(best_start, tmp);
	}
	// ft_printf("len of new a %d\n", best_start->len);
	// ft_printf("best_start = %d\n", best_start->starting->nb);
	// g = go_to_starting_pos(best_start, g);
	// print_list(g);
	g = sorting_a(g, best_start->starting);
	// print_list(g);
	free(best_start);
	return (g);
}
