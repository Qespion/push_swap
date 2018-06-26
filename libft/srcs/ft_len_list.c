/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:39:04 by oespion           #+#    #+#             */
/*   Updated: 2018/06/26 17:46:54 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_list(t_list *list)
{
	int		r;
	t_list	*start;

	start = list;
	r = 1;
	while (start->next != list)
	{
		r++;
		start = start->next;
	}
	return (r);
}

int		ft_len_part_list(t_list *list, int	attribut)
{
	int		len;
	t_list	*start;

	start = list;
	len = 0;
	while (start->p == attribut && start->next != list)
		start = start->next;
	while (start->p != attribut && start->next != list)
		start = start->next;
	if (start->p != attribut && start->next->p == attribut)
		start = start->next;
	while (start->p == attribut && start->next != list)
	{
		start = start->next;
		len++;
	}
	if (list->p == attribut && start->next == list)
	{
		start = start->next;
		len++;
		while (start->p == attribut && start->next != list)
		{
			start = start->next;
			len++;
		}
	}
	return (len);
}

int	ft_len_list_w_limit(t_list *list, int *limit)
{
	int		len;
	t_list	*start;

	start = list;
	len = 0;
	while (start->p >= limit[0] && start->p <= limit[1] && start->next != list)
		start = start->next;
	while ((start->p < limit[0] || start->p > limit[0]) && start->next != list)
		start = start->next;
	if ((start->p < limit[0] || start->p > limit[0]) && start->next->p >= limit[0] && start->next->p <= limit[1])
		start = start->next;
	while (start->p >= limit[0] && start->p <= limit[1] && start->next != list)
	{
		start = start->next;
		len++;
	}
	if (start->p >= limit[0] && start->p <= limit[1] && start->next == list)
	{
		start = start->next;
		len++;
		while (start->p >= limit[0] && start->p <= limit[1] && start->next != list)
		{
			start = start->next;
			len++;
		}
	}
	return (len);
}