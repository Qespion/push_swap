/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:20:15 by oespion           #+#    #+#             */
/*   Updated: 2018/04/04 11:41:08 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	r;

	r = 0;
	while (r < n)
	{
		if (((unsigned char*)s)[r] == (unsigned char)c)
			return ((void*)s + r);
		r++;
	}
	return (NULL);
}
