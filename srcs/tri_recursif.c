/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_recursif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:06:10 by oespion           #+#    #+#             */
/*   Updated: 2018/06/28 12:05:42 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list	**push_in_other(t_list **g, int lst, int **glimit)
{

	return (g);
}

t_list **tri_lst(t_list **g, int lst, int *limit)
{
	int	*glimit[3];
	int	limit1[2];
	int	limit2[2];
	int	limit3[2];
	int	nb_partition;

	nb_partition = calc_nb_partition(g, ft_len_list(g[0]));
	limit1[0] = 1;
	limit1[1] = nb_partition / 3;
	limit2[1] = nb_partition / 3 * 2;
	limit2[0] = nb_partition / 3 + 1;
	limit3[1] = nb_partition;
	limit3[0] = nb_partition / 3 * 2 + 1;
	glimit[0] = limit1;
	glimit[1] = limit2;
	glimit[2] = limit3;
	push_in_other(g, 0, glimit);
	return (g);
}

t_list	**tri_recursif(t_list **g)
{
	int	glimit[2];
	glimit[0] = 1;
	glimit[1] = calc_nb_partition(g, ft_len_list(g[0]));

	g = tri_lst(g, 0, glimit);
	exit(0);
	return (g);
}
