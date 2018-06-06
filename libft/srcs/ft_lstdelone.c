/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:08:49 by oespion           #+#    #+#             */
/*   Updated: 2018/06/06 15:27:15 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelone(t_list *new)
{
	new->prev->next = new->next;
	new->next->prev = new->prev;
	new->next = NULL;
	new->prev = NULL;
	free(&new->nb);
	return (new);
}
