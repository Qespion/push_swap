/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:32 by oespion           #+#    #+#             */
/*   Updated: 2018/04/05 12:34:51 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	r;

	r = 0;
	if (!s1 || !s2)
		return (0);
	while (r < n)
	{
		if (s1[r] != s2[r])
			return (0);
		if (s1[r] == '\0' && s2[r] == '\0')
			return (1);
		r++;
	}
	return (1);
}
