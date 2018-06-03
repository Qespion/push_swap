/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:35 by oespion           #+#    #+#             */
/*   Updated: 2018/04/04 12:10:08 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	r;
	int	l_size;

	i = 0;
	r = 0;
	l_size = 0;
	while (little[l_size])
		l_size++;
	if (l_size == 0)
		return (char *)(big);
	while (big[i])
	{
		while (little[r] == big[i + r] && (size_t)(r + i) < len)
		{
			if (r == l_size - 1)
				return (char *)(big + i);
			r++;
		}
		r = 0;
		i++;
	}
	return ((char *)NULL);
}
