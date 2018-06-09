/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:05:53 by oespion           #+#    #+#             */
/*   Updated: 2018/06/09 13:38:35 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int	check_single(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	if (a->nb <= a->next->nb)
		a = a->next;
	while (a->next != tmp && (a->nb <= a->next->nb))
		a = a->next;
	if (a->next == tmp)
		return(0);
	return (1);
}

/*
**	if both ok -> 2
**	if only a is ok -> 1
**	if only b is ok -> 0
**	if noone -> -1
*/

int	check_both_list(t_list **gb)
{
	int	r;

	r = 2;
	if (check_single(gb[0]))
		r = 0;
	if (check_single(gb[1]))
	{
		if (r == 0)
			r = -1;
		else
			r = 1;
	}
	return (r);
}
