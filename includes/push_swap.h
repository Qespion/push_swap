/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:14:27 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 15:30:33 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void	solver(t_list *a);
t_list	*create_a_from_str(char *str);
t_list	*create_a(int ac, char **av);
void	solver(t_list *a);

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