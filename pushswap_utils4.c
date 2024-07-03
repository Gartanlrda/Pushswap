/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:26:17 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/03 19:11:07 by ggoy             ###   ########.fr       */
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
        if (temp->content.index >= quarter)
            temp = temp->next;
        else
            return (0);
    }
    return (1);
}

void    sortin_list(t_list **a)
{
    int quarter;
    t_list  *b;
    
    b = NULL;
    quarter = ft_lstsize(*a) / 4;
    while (check_sort(*a) == 0)
    {
    //prendre 1er tiers
        while (check_quarter(*a, quarter) == 0)
        {
            update_position(*a);
            update_position(b);
            
        }
        quarter += ((ft_lstsize(*a) + ft_lstsize(b)) / 4);
    }
    //push le tiers + pre trier
    //passer au tiers suivant
}
