/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:26:17 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/07 00:39:39 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    update_position(t_list *a)
{
    t_list  *temp;
    int     i;
    
    i = 0;
    temp = a;
    while (temp)
    {
        temp->content.position = i++;
        temp = temp->next;
    }
}

int check_quarter(t_list *a, int quarter)
{
    t_list  *temp;

    temp = a;
    while (temp)
    {
        if (temp->content.index > quarter)
            temp = temp->next;
        else
            return (0);
    }
    return (1);
}

void find_best_op(t_list **a, t_list **b, int quarter)
{
    if ((*a)->content.index <= quarter && three_highest(a) == 1)
        pb(a, b);
    else
        rra(a);
}
void    push_in_a(t_list **a, t_list **b)
{
    while (*b)
    {
        //if ((*a)->next->content.index > (*a)->content.index)
          //  sa(a);
        if ((*a)->content.index < (*b)->content.index)
            good_position(a, b);
        //else if ((*a)->content.index > (ft_lstlast(*a)->content.index))
        //    ra(a);
        else
            pa(a, b);
    }
}

void    sortin_list(t_list **a)
{
    int quarter;
    t_list  *b;
    
    b = NULL;
    quarter = index_max(a) / 33;
    while (ft_lstsize(*a) > 3 && check_quarter((*a), quarter) == 0)
    {
        while (ft_lstsize(*a) > 3 && check_quarter((*a), quarter) == 0)
        {
            find_best_op(a, &b, quarter);
            if (ft_lstsize(b) > 1 && b->content.index < b->next->content.index)
                sb(&b);
        }
        quarter += quarter;
    }
    sortin_three(a);
    good_position(a, &b);
    update_position(*a);
}
