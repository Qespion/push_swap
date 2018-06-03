/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:22:37 by oespion           #+#    #+#             */
/*   Updated: 2018/05/01 14:42:35 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cw(char const *s, char c)
{
	int	r;
	int	count;

	count = 2;
	r = 0;
	while (s[r])
	{
		if (s[r] == c)
			count++;
		while (s[r] == c)
			r++;
		r++;
	}
	return (count);
}

static int		ft_word_len(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		r;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	r = 0;
	if (!s || !c || !(tab = (char**)malloc(sizeof(char*) * (ft_cw(s, c) + 1))))
		return (NULL);
	while (s[r])
	{
		while (s[r] == c)
			r++;
		if (!(s[r]))
			break ;
		if (!(tab[i] = (char*)malloc(sizeof(char) * ft_word_len(s, c, r))))
			return (NULL);
		while (s[r] != c && s[r] != '\0')
			tab[i][j++] = s[r++];
		j = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
