/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:38:15 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/06 08:34:31 by ggoy             ###   ########.fr       */
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

void    good_position(t_list **a, t_list **b)
{
    int i;

    i = 0;
    while (*b)
    {
        if (ft_lstsize(*b) > 1 && (*b)->next->content.index == ((*a)->content.index - 1))
            sb(b);
        if (((*b)->content.index == ((*a)->content.index - 1)) || ((*b)->content.index == ((*a)->content.index - 2)))
            pa(a, b);
        else if ((*a)->content.index > (*a)->next->content.index)
            sa(a);
        else if (i > 0)
        {
            while (i > 0)
            {
                if (((*b)->content.index == ((*a)->content.index - 1)) || ((*b)->content.index == ((*a)->content.index - 2)))
                    pa(a, b);
                else
                {
                    rrb(b);
                    i--;
                }//trouver un moyen d'alterner si le -2 est push
            }
        }
        else
            while (((*b)->content.index != ((*a)->content.index - 1)) && ((*b)->content.index != ((*a)->content.index - 2)))
            {
                printf("a:%i - b:%i\n", (*a)->content.index, (*b)->content.index);
                rb(b);
                i++;
            }
    }
}

int    three_highest(t_list **a)
{
    int max;

    max = index_max(a);
    if ((*a)->content.index > max - 3)
        return (0);
    else
        return (1);
}