/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:14:27 by oespion           #+#    #+#             */
/*   Updated: 2018/06/10 13:51:10 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
**	push swap
*/

int		better_in_reverse_rb(t_list **g, int base_count, t_list *biggest);
int		better_in_rrr(t_list **g, int base_count, t_list *biggest);
int		better_in_reverse_ra(t_list **g, int base_count, t_list *biggest);

t_list	*find_lowest(t_list *lst);
t_list	*find_biggest(t_list *lst);
t_list	**rotate_to_lower(t_list **lst);

void	print_list(t_list **global);
void	solver(t_list *a);
t_list	*create_a_from_str(char *str);
t_list	*create_a(int ac, char **av);
int		check_both_list(t_list **gb);
t_list	**push_in_b(t_list **g);
t_list	**push_back_in_a(t_list **g);

/*
**	checker
*/
void	print_a(t_list *a);
int		create_list_malloc(t_list *a);
void		create_list(t_list *a);
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