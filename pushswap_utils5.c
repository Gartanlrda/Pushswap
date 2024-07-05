/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:38:15 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/05 20:22:12 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int index_max(t_list **a)
{
    int max;
    t_list  *temp;
    
    max = 0;
    temp = *a;
    while (temp)
    {
        if (temp->content.index > max)
            max = temp->content.index;
        temp = temp->next;
    }
    return (max);
}

void    good_position(t_list **a, t_list **b)
{
    int i;

    i = 0;
    if ((*b)->next->content.index > (*b)->content.index)
        sb(b);
    while ((*a)->content.index < (*b)->content.index)
    {
        ra(a);
        i++;
    }
    pa(a, b);
    while (i != 0)
    {
        rra(a);
        i--;
    }
}

int    three_highest(t_list **a)
{
    int max;

    max = index_max(a);
    if ((*a)->content.index > max - 2)
        return (0);
    else
        return (1);
}