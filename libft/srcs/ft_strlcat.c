/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:23 by oespion           #+#    #+#             */
/*   Updated: 2018/04/04 11:23:52 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	r;
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	r = 0;
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (dst[r] && r < size - 1)
		r++;
	while (r < size - 1 && src[i])
	{
		dst[r] = src[i];
		r++;
		i++;
	}
	dst[r] = '\0';
	return (dst_len + src_len);
}
