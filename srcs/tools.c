/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:42:57 by oespion           #+#    #+#             */
/*   Updated: 2018/06/08 10:47:29 by oespion          ###   ########.fr       */
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
	while (lst->next != start)
	{
		if (lst->nb < nb)
		{
			nb = lst->nb;
			adr = lst;
		}
		lst = lst->next;
	}
	return (adr);
}