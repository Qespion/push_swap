/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:30:44 by oespion           #+#    #+#             */
/*   Updated: 2018/07/15 15:19:47 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**swap_both_list(t_list **g)
{
	while (g[0]->next != g[0])
	{
		ft_printf("pb\n");
		g = push_b(g);
	}
	return (g);
}
