/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:23:37 by oespion           #+#    #+#             */
/*   Updated: 2018/07/06 13:11:18 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "push_swap.h"

t_list  **create_new(t_list **g)
{
    t_list  **new_list;
    t_list  *cpy;
    t_list  *new_a;

    cpy = g[0];
    if (!(new_list = (t_list**)malloc(sizeof(t_list*) * 2)))
        return (0);
    new_a = ft_lstnew(cpy->nb);
    new_a = new_a->next;
    cpy = cpy->next;
    new_list[0] = new_a;
    new_list[1] = NULL;
    while (cpy != g[0])
    {
        new_list = ft_insert_one(new_list, 0, cpy->nb);
        cpy = cpy->next;
    }
    return (new_list);
}

t_list  **put_partition_in_list(t_list **nlist, t_list **g)
{
    t_list  *tmp;

    tmp = g[0];
    while (tmp->next != g[0])
    {
        while (tmp->nb != nlist[0]->nb)
            nlist[0] = nlist[0]->next;
        tmp->p = nlist[0]->p;
        tmp = tmp->next;
    }
    while (tmp->nb != nlist[0]->nb)
        nlist[0] = nlist[0]->next;
    tmp->p = nlist[0]->p;
    return (g);
}

t_list  **new_attribut(t_list **nlist, int len, int nb_partition)
{
    t_list  *lst;
    int i;
    int r;
    int part_size;

    part_size = len / nb_partition;
    lst = nlist[0];
    i = 1;
    r = 1;
    while (lst->next != nlist[0])
    {
        if (i > part_size)
        {
            i = 1;
            r < nb_partition ? r++ : 0;
        }
        i++;
        lst->p = r;
        lst = lst->next;
    }
    lst->p = r;
    return (nlist);
}

int     calc_nb_partition(t_list **nlist, int len)
{
    int nb;
    int r;
    t_list  *tmp;

    tmp = nlist[0];
    r = 0;
    nb = 1;
    while (tmp->next != nlist[0])
    {
        if (r >= 9)
        {
            r = 0;
            nb++;
        }
        r++;
        tmp = tmp->next;
    }
    return (nb);
}

int     calc_spe_list_partition(t_list *g)
{
    int     nb_partition;
    t_list  *tmp;
    t_list  *start_cmp;

    tmp = g;
    nb_partition = 0;
    while (tmp->next != g)
    {
        start_cmp = g;
        while (start_cmp != tmp)
        {
            if (start_cmp->p == tmp->p)
                break ;
            start_cmp = start_cmp->next;
        }
        if (start_cmp == tmp)
        nb_partition++;
        tmp = tmp->next;
    }
    return (nb_partition);
}

int     highest_partition(t_list *g)
{
    int      highest;
    t_list  *tmp;

    tmp = g;
    if (g == NULL)
        return (0);
    highest = g->p;
    while (tmp->next != g)
    {
        if (tmp->p > highest)
            highest = tmp->p;
        tmp = tmp->next;
    }
    return (highest);
}

int     lowest_partition(t_list *g)
{
    int lowest;
    t_list  *tmp;

    tmp = g;
    if (g == NULL)
        return (0);
    lowest = g->p;
    while (tmp->next != g)
    {
        if (tmp->p < lowest)
            lowest = tmp->p;
        tmp = tmp->next;
    }
    return (lowest);
}

t_list  **partition_list(t_list **g)
{
    int     nb_partition;
    t_list  **nlist;
    int     len;

    nlist = swap_basic(create_new(g));
    len = ft_len_list(nlist[0]);
    nlist = rotate_to_lower(nlist);
    nb_partition = calc_nb_partition(nlist, len);
    nlist = new_attribut(nlist, len, nb_partition);
    // print_list(nlist);
    g = put_partition_in_list(nlist, g);
    ft_lstdel(nlist[0]);
    return (g);
}
