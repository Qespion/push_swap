/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:29 by oespion           #+#    #+#             */
/*   Updated: 2018/04/04 12:11:58 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	r;

	r = 0;
	if (n < 1)
		return (0);
	while ((unsigned char)s1[r] == (unsigned char)s2[r]
			&& s1[r] != '\0' && r < n)
	{
		if (r == (n - 1))
			return (0);
		r++;
	}
	return ((unsigned char)s1[r] - (unsigned char)s2[r]);
}
