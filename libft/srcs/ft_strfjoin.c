/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:51:13 by oespion           #+#    #+#             */
/*   Updated: 2018/06/10 10:45:00 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char *s1, char *s2)
{
	char	*str;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(str, len + 1);
	//ft_printf("s1 = %s\n", s1);
	// if (s1)
    // {
    //     free((char*)s1);
    //     s1 = NULL;
    // }
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}
