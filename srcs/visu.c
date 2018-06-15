/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12:10:17 by oespion           #+#    #+#             */
/*   Updated: 2018/06/15 10:26:49 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

void	ft_start_visu(t_list *a)
{
	void	*mlx_ad;
	void	*mlx_wds;

	mlx_ad = mlx_init();
	mlx_wds = mlx_new_window(mlx_ad, 200, 200, "Push Swap");
	// mlx_pixel_put(mlx_ad, mlx_wds, 100, 100, 0xFFFFFF);
	// mlx_pixel_put(mlx_ad, mlx_wds, 101, 100, 0xFFFFFF);
	// mlx_pixel_put(mlx_ad, mlx_wds, 102, 100, 0xFFFFFF);
	// mlx_pixel_put(mlx_ad, mlx_wds, 103, 100, 0xFFFFFF);
	// mlx_pixel_put(mlx_ad, mlx_wds, 101, 100, 0xFFFFFFF);
	mlx_string_put(mlx_ad, mlx_wds, 0, 0, 0xFF0000, ft_itoa(a->nb));
	mlx_string_put(mlx_ad, mlx_wds, 0, 0, 0xFF0000, ft_itoa(a->next->nb));
	mlx_loop(mlx_ad);
}
