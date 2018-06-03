/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:01 by oespion           #+#    #+#             */
/*   Updated: 2018/04/04 12:14:24 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	r;

	r = 0;
	while ((unsigned char)s1[r] == (unsigned char)s2[r]
			&& s1[r] != '\0')
		r++;
	return ((unsigned char)s1[r] - (unsigned char)s2[r]);
}
