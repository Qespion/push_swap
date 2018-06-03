/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:23:25 by oespion           #+#    #+#             */
/*   Updated: 2018/04/07 19:02:51 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;
	int		r;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	r = 0;
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (start > end)
		return (ft_strnew(0));
	if (!(str = ft_strnew(end - start + 1)))
		return (NULL);
	while (start <= end)
		str[r++] = s[start++];
	str[r] = '\0';
	return (str);
}
