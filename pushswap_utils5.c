/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:38:15 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/07 05:13:41 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int index_max(t_list **a)
{
    int max;
    t_list  *temp;
    
    max = -2147483647;
    temp = *a;
    while (temp)
    {
        if (temp->content.index > max)
            max = temp->content.index;
        temp = temp->next;
    }
    return (max);
}

int index_min(t_list **a)
{
    int min;
    t_list  *temp;

    min = 2147483647;
    temp = *a;
    while (temp)
    {
        if (temp->content.index < min)
            min = temp->content.index;
        temp = temp->next;
    }
    return (min);
}

int    three_highest(t_list **a, int value)
{
    int max;

    max = index_max(a);
    if (value > max - 3)
        return (0);
    else
        return (1);
}

void    good_position(t_list **a, t_list **b)
{
    int i;
    t_list  *tmp;
    
    while (*b)
    {
        if (is_possible(a, b) == 1)
            pa(a, b);
        while ((*b) && i > 0)
        {
            if (is_possible(a, b) == 1)
                pa(a, b);
            else
            {
                if (is_possible(a, b) == 1)
                    pa(a, b);
                rrb(b);
                i--;
            }
        }
        while (ft_lstsize(*b) > 1 && is_possible(a, b) == 0)
        {
            rb(b);
            i++;
        }
    }
}

int is_possible(t_list **a, t_list **b)
{
    if (*b)
    {
        if (ft_lstsize(*b) > 1 && (*b)->next->content.index == ((*a)->content.index - 1))
            sb(b);
        if ((*a)->content.index == ((*a)->next->content.index + 1))
            sa(a);
        if (((*a)->content.index == ((*a)->next->content.index - 1))
            && (((*b)->content.index == ((*a)->content.index - 1))
            || ((*b)->content.index == ((*a)->content.index - 2))))
            return (1);
        else if (((*a)->content.index == ((*a)->next->content.index - 2))
            && (((*b)->content.index == ((*a)->content.index + 1))))
        {
            pa(a, b);
            sa(a);
        }
        else
            return (0);
    }
    return (0);
}
