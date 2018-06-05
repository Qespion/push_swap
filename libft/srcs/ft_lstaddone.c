/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:19:45 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 15:42:44 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddone(int nb, t_list *start, t_list *current)
{
	t_list	*new;

	new = ft_lstnew(nb);
	current->next = new;
	new->prev = current;
	new->next = start;
	start->prev = new;
	return (new);
}
