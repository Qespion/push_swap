/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:28 by oespion           #+#    #+#             */
/*   Updated: 2018/04/09 13:12:54 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int	r;
	int	i;

	r = 0;
	i = ft_strlen(dest);
	while (src[r] && (size_t)r < n)
	{
		dest[i] = ((char*)src)[r];
		i++;
		r++;
	}
	dest[i] = '\0';
	return (dest);
}
