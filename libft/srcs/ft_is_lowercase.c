/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_lowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:15:51 by oespion           #+#    #+#             */
/*   Updated: 2018/04/07 15:18:16 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_lowercase(char *str)
{
	int	r;

	r = 0;
	while (str[r])
		r++;
	if (r == 0)
		return (1);
	r = 0;
	while (str[r] && str[r] <= 'z' && str[r] >= 'a')
		r++;
	if (str[r] == '\0')
		return (1);
	return (0);
}
