/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:12:32 by oespion           #+#    #+#             */
/*   Updated: 2018/08/16 13:58:26 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list *lst)
{
	t_list	*tmp;

	lst->prev->next = NULL;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = NULL;
		lst = tmp;
	}
}
