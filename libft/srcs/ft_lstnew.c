/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:50:56 by oespion           #+#    #+#             */
/*   Updated: 2018/08/14 18:21:37 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int nb)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	new->nb = nb;
	new->prev = new;
	new->next = new;
	new->p = 0;
	return (new);
}
