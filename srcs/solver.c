/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:16:19 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 16:11:08 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

void	solver(t_list *a)
{
	t_list	**global;
	t_list	*b;

	if (!(global = (t_list**)malloc(sizeof(t_list*) * 2)))
		return ;
	global[0] = a;
	global[1] = NULL;
	global = push_b(global);
	ft_printf("nb1 == %d\n", global[1]->nb);
	ft_printf("after nb1 == %d\n", global[0]->nb);
}
