/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:20:56 by oespion           #+#    #+#             */
/*   Updated: 2018/04/04 11:45:56 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t r;

	r = 0;
	while (r < len)
	{
		((unsigned char*)b)[r] = (unsigned char)c;
		r++;
	}
	return (b);
}
