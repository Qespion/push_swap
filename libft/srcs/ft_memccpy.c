/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:20:06 by oespion           #+#    #+#             */
/*   Updated: 2018/04/07 10:50:54 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *cpy_src;
	char *cpy_dst;

	cpy_src = (char*)src;
	cpy_dst = (char*)dst;
	while (n > 0 && *cpy_src != (char)c)
	{
		n--;
		*cpy_dst++ = *cpy_src++;
	}
	if (n > 0)
	{
		*cpy_dst++ = *cpy_src++;
		return ((void*)cpy_dst);
	}
	else
		return (NULL);
}
