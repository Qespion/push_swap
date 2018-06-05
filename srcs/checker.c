/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:49:40 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 11:16:26 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	main(int ac, char **av)
{
	int	nb;
	int	i;

	i = 2;
	if (ac < 2)
	{
		ft_printf("OK\n");
		return (0);
	}
	nb = ft_atoi(av[1]);
	while (i < ac)
	{
		if (nb > ft_atoi(av[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	ft_printf("OK\n");
	return (0);
}
