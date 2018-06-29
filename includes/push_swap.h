/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:14:27 by oespion           #+#    #+#             */
/*   Updated: 2018/06/29 13:49:57 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mlx.h"
/*
** BOGO SORT
*/
#include <time.h>
#include <stdlib.h>

typedef struct  s_poz
{
    t_list  *ending;
    t_list  *starting;
    int     len;
}               t_poz;

typedef struct  s_visu
{
    int is_active;
    void    *mlx_ad;
    void    *mlx_wds;
}               t_visu;

/*
**	push swap
*/


t_list	**old_push_in_b(t_list **g);
t_list	**subdivide(t_list **g);
t_list	**swap_both_list(t_list **g);

int	ft_len_list_w_limit(t_list *list, int *limit);
int		lower_partition_left(t_list *lst, int partition);
t_list	**tri_recursif(t_list **g);

int     calc_nb_partition(t_list **nlist, int len);
int		partition_nb(t_list **g);
int		lower_partition(t_list *lst);

t_list  **partition_list(t_list **g);
t_list	**go_to_starting_pos(t_poz *best_start, t_list **g);
t_poz   *best_starting_pos(t_poz *best_start, t_list *tmp);
int		middle(t_list *lst);
int		ft_len_part_list(t_list *list, int	attribut);
int		real_median(t_list *lst);
t_list	**divide(t_list **g);

int		upper_than_mid_b(t_list **g, int mid_nb);
int		number_in_the_middle(t_list *g);
t_list	**tri_b(t_list **g);

int		better_in_reverse_rb(t_list **g, int base_count, t_list *biggest);
int		better_in_rrr(t_list **g, int base_count, t_list *biggest);
int		better_in_reverse_ra(t_list **g, int base_count, t_list *biggest);

t_list	*find_lowest(t_list *lst);
t_list	*find_biggest(t_list *lst);
t_list	**rotate_to_lower(t_list **lst);

t_list	**swap_basic(t_list **global);
void	print_list(t_list **global);
void	solver(t_list *a, int bogo);
t_list	*create_a_from_str(char *str);
t_list	*create_a(int ac, char **av, int teube);
int		check_both_list(t_list **gb);
t_list	**push_in_b(t_list **g);
t_list	**push_back_in_a(t_list **g);
int		ra_or_rra(t_list **g, t_list *start_a);
int		check_list(t_list *start);

/*
**	check best solutions for push swap
*/

t_list	**do_op(t_list **g, int rotate_b, int rotate_a);

int		calc_other_rb(t_list **g, int nb_max, t_list *biggest, int rotation_of_b);
int		calc_ra(t_list **g, t_list *biggest);
int		calc_rra(t_list **g, t_list *biggest);

/*
**	random
*/

int		is_sort(t_list *lowest);
t_list	**allfunctions(t_list **g, int r);

/*
**	checker
*/

void	ft_start_visu(t_list *a);
void	print_a(t_list *a);
int		create_list_malloc(t_list *a);
void	create_list(t_list *a);
t_list	**apply_checker(t_list **g, char *str);

/*
**	mod functions
*/

t_list	**swap_a(t_list **global);
t_list	**swap_b(t_list **global);
t_list	**swap_ss(t_list **global);

t_list	**push_a(t_list **global);
t_list	**push_b(t_list **global);

t_list	**rotate_a(t_list **global);
t_list	**rotate_b(t_list **global);
t_list	**rotate_rr(t_list **global);

t_list	**reverse_rotate_a(t_list **global);
t_list	**reverse_rotate_b(t_list **global);
t_list	**reverse_rotate_rr(t_list **global);

#endif
