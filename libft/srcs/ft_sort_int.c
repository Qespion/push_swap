/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:24:07 by oespion           #+#    #+#             */
/*   Updated: 2018/04/07 13:24:19 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int(int *lst, size_t len)
{
	size_t	r;
	int		tmp;

	r = 0;
	while (r < len - 1)
	{
		if (lst[r] > lst[r + 1])
		{
			tmp = lst[r];
			lst[r] = lst[r + 1];
			lst[r + 1] = tmp;
			r = -1;
		}
		r++;
	}
}
