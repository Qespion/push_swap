/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:56:52 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 17:14:28 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_insert_one(t_list **global, int lst_nb, int nb)
{
	t_list	*new;
	t_list	*before;
	t_list	*after;

	new = ft_lstnew(nb);
	before = global[lst_nb]->prev;
	after = global[lst_nb];
	before->next = new;
	after->prev = new;
	global[lst_nb] = new;
	new->next = after;
	new->prev = before;
	return (global);
}