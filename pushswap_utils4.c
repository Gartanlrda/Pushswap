/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:26:17 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/04 06:44:44 by ggoy             ###   ########.fr       */
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
    if ((*a)->content.index <= quarter)
        pb(a, b);
    else if ((*a)->next->content.index <= quarter)
        sa(a);
    else
        rra(a);
}
void    push_in_a(t_list **a, t_list **b)
{
    while (*b)
        pa(a, b);
}

void    sortin_list(t_list **a)
{
    int final;
    int quarter;
    t_list  *b;
    t_list  *tmp;
    
    final = ft_lstsize(*a);
    b = NULL;
    quarter = ft_lstsize(*a) / 4;
    while (ft_lstsize(*a) > 3 && check_quarter(*a, quarter) == 0)
    {
        while (ft_lstsize(*a) > 3 && check_quarter((*a), quarter) == 0)
        {
            update_position(*a);
            update_position(b);
            find_best_op(a, &b, quarter);
            if (ft_lstsize(b) > 1 && b->content.index < b->next->content.index)
                sb(&b);
        }
        quarter = quarter + ((ft_lstsize(*a) + ft_lstsize(b)) / 4);
    }
    sortin_three(a);
    push_in_a(a, &b);
}
