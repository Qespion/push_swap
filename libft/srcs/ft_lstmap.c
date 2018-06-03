/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 09:54:11 by oespion           #+#    #+#             */
/*   Updated: 2018/04/09 11:26:42 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*tmp;
	t_list	*next;

	start = NULL;
	if (!lst || !f)
		return (NULL);
	start = f(lst);
	lst = lst->next;
	tmp = start;
	while (lst)
	{
		next = f(lst);
		tmp->next = next;
		tmp = next;
		lst = lst->next;
	}
	return (start);
}
