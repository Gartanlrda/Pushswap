/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:26:17 by ggoy              #+#    #+#             */
/*   Updated: 2024/07/07 23:43:00 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    update_position(t_list *a)
{
    t_list  *temp;
    int     i;
    
    i = 1;
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

void    find_best_op(t_list**a, t_list **b, int quarter)
{
    int i;

    update_position(*a);
//    printf("%i\n", quarter);
//    printf("front: %i back: %i\n", find_front(a, quarter), find_back(a, quarter));
    if (find_front(a, quarter) < find_back(a, quarter))
    {
        i = find_front(a, quarter);
        while (i > 0)
        {
            ra(a);
            i--;
        }
        pb(a, b);
    }
    else
    {
        i = find_back(a, quarter);
        while (i > 0)
        {
            rra(a);
            i--;
        }
        pb(a, b);
    }
}

int find_front(t_list **a, int quarter)
{
    int     i;
    t_list  *tmp;
// appliquer le tri opti pour le push en a
    i = 0;
    tmp = *a;
    while (tmp->content.index > quarter || three_highest(a, tmp->content.index) == 0)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

int find_back(t_list **a, int quarter)
{
    t_list  *tmp;
    int     pos;

    pos = (ft_lstlast(*a)->content.position);
    while (1)
    {
        tmp = *a;
        while (tmp->content.position < pos)
            tmp = tmp->next;
        if (tmp->content.index <= quarter && three_highest(a, tmp->content.index) == 1)
            return (ft_lstlast(*a)->content.position - tmp->content.position + 1);
        else
            pos--;
    }
}

void    push_in_a(t_list **a, t_list **b)
{
    while (*b)
    {
        if ((*a)->content.index < (*b)->content.index)
            good_position(a, b);
        else
            pa(a, b);// Trouver pourquoi ca trie mal
    }
}

void    sortin_list(t_list **a)
{
    int quarter;
    int divider;
    t_list  *b;
    //t_list  *tmp;
    
    b = NULL;
    divider = index_max(a) / 2;
    quarter = 25;
    while (ft_lstsize(*a) > 3 && check_quarter((*a), quarter) == 0)
    {
        while (ft_lstsize(*a) > 3 && check_quarter((*a), quarter) == 0)
        {
            find_best_op(a, &b, quarter);
            if (ft_lstsize(b) > 1 && b->content.index < b->next->content.index)
                sb(&b);
        }
        quarter = quarter + 25;
    }
    sortin_three(a);
    /*tmp = b;
	while (tmp)
	{
		printf("b - position: %i - index: %i - element:%i\n", tmp->content.position, tmp->content.index, tmp->content.element);
		tmp = tmp -> next;
	}*/
    good_position(a, &b);
    update_position(*a);
}
