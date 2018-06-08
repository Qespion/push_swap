/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:45 by oespion           #+#    #+#             */
/*   Updated: 2018/06/08 19:20:06 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

int		create_list(t_list *a)
{
	t_list	**global;
	char	*str;

	if (!(global = (t_list**)malloc(sizeof(t_list*) * 2)))
		return (0);
	while (get_next_line(0, &str) == 1)
	{
		ft_printf("%s\n", str);
	}
	global[0] = a;
	global[1] = NULL;
	free(global);
	return (0);
}