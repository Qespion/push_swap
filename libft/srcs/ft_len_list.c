/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:39:04 by oespion           #+#    #+#             */
/*   Updated: 2018/06/18 17:43:05 by oespion          ###   ########.fr       */
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
