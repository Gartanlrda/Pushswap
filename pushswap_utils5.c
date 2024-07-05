/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:38:15 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/05 02:54:50 by ggoy             ###   ########.fr       */
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